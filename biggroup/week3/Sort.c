#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
double measure_sorting_time(void (*sort_function)(int[], int), int arr[], int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sort_function(arr, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
void test_sorting_time(void (*sort_function)(int[], int), const char* sort_name, FILE* file) {
    int sizes[] = { 10000, 50000, 200000 };
    for (int i = 0; i < 3; i++) {
        int n = sizes[i];
        int* arr = (int*)malloc(n * sizeof(int));
        srand(time(NULL));
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000000; // ���������
        }
        double time_taken = measure_sorting_time(sort_function, arr, n);
        printf("%s sorting %d elements took %f seconds\n", sort_name, n, time_taken);
        fprintf(file, "%s sorting %d elements took %f seconds\n", sort_name, n, time_taken);
        free(arr);
    }
}
void test_small_data_sorting(void (*sort_function)(int[], int), const char* sort_name) {
    int n = 100;
    int iterations = 100000;
    int* arr = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    double total_time = 0;
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000; // ����С�������������
        }
        total_time += measure_sorting_time(sort_function, arr, n);
    }
    printf("%s sorting %d elements %d times took %f seconds\n", sort_name, n, iterations, total_time);
    free(arr);
}
void print_arr_to_file(FILE* file, int* arr, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fprintf(file, "\n");
}

void sort_file_data(const char* filename, void (*sort_function)(int[], int)) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int n = 0;
    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        n++;
    }
    rewind(file); // �����ļ�ָ�뵽�ļ���ʼ

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    sort_function(arr, n);

    // ���������������������д��������ӡ�򱣴浽��һ���ļ�
    // ...

    free(arr);
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int)); 
    int* R = (int*)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;

    }
    free(L);
    free(R);
}
void merge_sort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


void counting_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // ��̬���� count ����
    int* count = (int*)malloc((max + 1) * sizeof(int));
    if (count == NULL) {
        // ����ʧ�ܣ��������
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // ����ÿ��Ԫ�ص�Ƶ��
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // �޸� count ���飬ÿ��λ�õ�ֵ�Ǹ�Ԫ������������е�λ��
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // ��̬���� output ����
    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL) {
        // ����ʧ�ܣ��������
        printf("Memory allocation failed.\n");
        free(count); // �ͷ� count ����
        exit(1);
    }

    // ����������
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // ��������Ԫ�ظ��ƻ�ԭ����
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // �ͷŶ�̬������ڴ�
    free(count);
    free(output);
}

void radix_sort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int* output = (int*)malloc(n * sizeof(int));
        int count[10] = { 0 };
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
            
        }
        free(output);
    }
    
}
void print_arr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertion_sort_adapter(int arr[], int n) {
    insertion_sort(arr, n);
}

void quick_sort_adapter(int arr[], int n) {
    quick_sort(arr, 0, n - 1);
}

void merge_sort_adapter(int arr[], int n) {
    merge_sort(arr, 0, n - 1);
}

void counting_sort_adapter(int arr[], int n) {
    counting_sort(arr, n);
}

void radix_sort_adapter(int arr[], int n) {
    radix_sort(arr, n);
}
void sortArray(int* arr, int n) {
    int p1 = 0; // ָ���һ����0Ԫ�ص�����
    int p2 = n - 1; // ָ�����һ����2Ԫ�ص�����
    int i = 0; // �������������

    while (i <= p2) {
        if (arr[i] == 0) {
            // �����ǰԪ����0������p1λ�õ�Ԫ�ؽ���������p1��ǰ�ƶ�һλ
            int temp = arr[i];
            arr[i] = arr[p1];
            arr[p1] = temp;
            p1++;
            i++; // ���ڽ���������Ԫ���Ѿ��Ǵ�����ģ�����i���Լ�����ǰ�ƶ�
        }
        else if (arr[i] == 2) {
            // �����ǰԪ����2������p2λ�õ�Ԫ�ؽ���������p2����ƶ�һλ
            int temp = arr[i];
            arr[i] = arr[p2];
            arr[p2] = temp;
            p2--;
            // ���ڽ���������Ԫ�ػ���Ҫ��������i���ֲ���
        }
        else {
            // �����ǰԪ����1����ֱ����ǰ�ƶ�i
            i++;
        }
    }
}

void menu() {
    printf("�����㷨ѡ��\n");
    printf("1. ��������\n");
    printf("2. ��������\n");
    printf("3. �鲢����\n");
    printf("4. ��������\n");
    printf("5. ��������\n");
    printf("6. �˳�\n");
    printf("7.��һ����Ŀ����\n");
    printf("8.�ڶ�����Ŀ����\n");
    printf("���������ѡ��1-8����");
    
}


    int main() {
        int arr[51];
        int n = sizeof(arr) / sizeof(arr[0]);
        int choice;
        FILE* output_file = fopen("output.txt", "w");
        if (output_file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        

        // �˵�����
        while (1) {
            printf("�����㷨ѡ��\n");
            printf("1. ��������\n");
            printf("2. ��������\n");
            printf("3. �鲢����\n");
            printf("4. ��������\n");
            printf("5. ��������\n");
            printf("6. �˳�\n");
            printf("7.��һ����Ŀ����\n");
            printf("8.�ڶ�����Ŀ����\n");
            printf("���������ѡ��1-8����");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                
                system("cls");
                // ���������
                srand(time(NULL));
                // ����50������100�������
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 180 + 200; // ��֤������100
                }
                printf("������50�������\n");
                print_arr(arr, n);
                insertion_sort(arr, n);
                printf("��������������: \n");
                print_arr(arr, n);
                test_sorting_time(insertion_sort, "Insertion", output_file);

                print_arr_to_file(output_file, arr, n);
                break;
            case 2:
               system("cls");
               srand(time(NULL));
               // ����50������100�������
               for (int i = 0; i < n; i++) {
                   arr[i] = rand() % 180 + 200; // ��֤������100
               }
                printf("������50�������\n");
                print_arr(arr, n);
                quick_sort(arr, 0, n - 1);
                printf("��������������: \n");
                print_arr(arr, n);
                test_sorting_time(quick_sort_adapter, "Quick", output_file);
                print_arr_to_file(output_file, arr, n);
                break;
            case 3:
                system("cls");
                srand(time(NULL));
                // ����50������100�������
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 180 + 200; // ��֤������100
                }
                printf("������50�������\n");
                print_arr(arr, n);
                merge_sort(arr, 0, n - 1);
                printf("�鲢����������: \n");
                print_arr(arr, n);
                test_sorting_time(merge_sort_adapter, "Merge", output_file);
                print_arr_to_file(output_file, arr, n);
                break;
            case 4:
                system("cls");
                srand(time(NULL));
                // ����50������100�������
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 180 + 200; // ��֤������100
                }
                printf("������50�������\n");
                print_arr(arr, n);
                counting_sort(arr, n);
                printf("��������������: \n");
                print_arr(arr, n);
                test_sorting_time(counting_sort, "Counting", output_file);
                print_arr_to_file(output_file, arr, n);
                break;
            case 5:
                system("cls");
                srand(time(NULL));
                // ����50������100�������
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 180 + 200; // ��֤������100
                }
                printf("������50�������\n");
                print_arr(arr, n);
                radix_sort(arr, n);
                printf("��������������: \n");
                print_arr(arr, n);
                test_sorting_time(radix_sort_adapter, "Radix", output_file);
                print_arr_to_file(output_file, arr, n);
                break;
            case 6:
                system("cls");
                printf("���˳�����\n");
                exit(0);
            case 7:
                system("cls");
                printf("��һ����Ŀ������\n");
                int arr1[] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };
                int n1 = sizeof(arr1) / sizeof(arr1[0]);

                sortArray(arr1, n1);

                for (int i = 0; i < n1; i++) {
                    printf("%d ", arr1[i]);
                }
                break;
            case 8:
                system("cls");
                printf("�ڶ�����Ŀ������\n");
                int arr2[] = { 5, 2, 8, 4, 3, 7, 6 };
                int n2 = sizeof(arr2) / sizeof(arr2[0]);
                int k = 4; // ����������0��ʼ�����Ե�3С��������Ϊ2
                quick_sort(arr2, 4, n2 - 1);
                printf("��3С������: %d\n", k);
                break;
            default:
                system("cls");
                printf("��Ч��ѡ��,�������������\n");
                getchar();
               break;
            }
        }
        fclose(output_file);
        return 0;
    }



