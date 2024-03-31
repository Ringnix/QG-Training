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
            arr[j] = rand() % 1000000; // 生成随机数
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
            arr[j] = rand() % 1000; // 生成小数据量的随机数
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
    rewind(file); // 重置文件指针到文件开始

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    sort_function(arr, n);

    // 排序后的数组可以在这里进行处理，例如打印或保存到另一个文件
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

    // 动态分配 count 数组
    int* count = (int*)malloc((max + 1) * sizeof(int));
    if (count == NULL) {
        // 分配失败，处理错误
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // 计数每个元素的频率
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 修改 count 数组，每个位置的值是该元素在输出数组中的位置
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 动态分配 output 数组
    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL) {
        // 分配失败，处理错误
        printf("Memory allocation failed.\n");
        free(count); // 释放 count 数组
        exit(1);
    }

    // 填充输出数组
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 将排序后的元素复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // 释放动态分配的内存
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
    int p1 = 0; // 指向第一个非0元素的索引
    int p2 = n - 1; // 指向最后一个非2元素的索引
    int i = 0; // 遍历数组的索引

    while (i <= p2) {
        if (arr[i] == 0) {
            // 如果当前元素是0，则与p1位置的元素交换，并将p1向前移动一位
            int temp = arr[i];
            arr[i] = arr[p1];
            arr[p1] = temp;
            p1++;
            i++; // 由于交换过来的元素已经是处理过的，所以i可以继续向前移动
        }
        else if (arr[i] == 2) {
            // 如果当前元素是2，则与p2位置的元素交换，并将p2向后移动一位
            int temp = arr[i];
            arr[i] = arr[p2];
            arr[p2] = temp;
            p2--;
            // 由于交换过来的元素还需要处理，所以i保持不变
        }
        else {
            // 如果当前元素是1，则直接向前移动i
            i++;
        }
    }
}

void menu() {
    printf("排序算法选择：\n");
    printf("1. 插入排序\n");
    printf("2. 快速排序\n");
    printf("3. 归并排序\n");
    printf("4. 计数排序\n");
    printf("5. 基数排序\n");
    printf("6. 退出\n");
    printf("7.第一道题目解析\n");
    printf("8.第二道题目解析\n");
    printf("请输入你的选择（1-8）：");
    
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
        

        // 菜单界面
        while (1) {
            printf("排序算法选择：\n");
            printf("1. 插入排序\n");
            printf("2. 快速排序\n");
            printf("3. 归并排序\n");
            printf("4. 计数排序\n");
            printf("5. 基数排序\n");
            printf("6. 退出\n");
            printf("7.第一道题目解析\n");
            printf("8.第二道题目解析\n");
            printf("请输入你的选择（1-8）：");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                
                system("cls");
                // 随机数种子
                srand(time(NULL));
                // 生成50个大于100的随机数
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 180 + 200; // 保证数大于100
                }
                printf("已生成50个随机数\n");
                print_arr(arr, n);
                insertion_sort(arr, n);
                printf("插入排序后的数组: \n");
                print_arr(arr, n);
                test_sorting_time(insertion_sort, "Insertion", output_file);

                print_arr_to_file(output_file, arr, n);
                break;
            case 2:
               system("cls");
               srand(time(NULL));
               // 生成50个大于100的随机数
               for (int i = 0; i < n; i++) {
                   arr[i] = rand() % 180 + 200; // 保证数大于100
               }
                printf("已生成50个随机数\n");
                print_arr(arr, n);
                quick_sort(arr, 0, n - 1);
                printf("快速排序后的数组: \n");
                print_arr(arr, n);
                test_sorting_time(quick_sort_adapter, "Quick", output_file);
                print_arr_to_file(output_file, arr, n);
                break;
            case 3:
                system("cls");
                srand(time(NULL));
                // 生成50个大于100的随机数
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 180 + 200; // 保证数大于100
                }
                printf("已生成50个随机数\n");
                print_arr(arr, n);
                merge_sort(arr, 0, n - 1);
                printf("归并排序后的数组: \n");
                print_arr(arr, n);
                test_sorting_time(merge_sort_adapter, "Merge", output_file);
                print_arr_to_file(output_file, arr, n);
                break;
            case 4:
                system("cls");
                srand(time(NULL));
                // 生成50个大于100的随机数
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 180 + 200; // 保证数大于100
                }
                printf("已生成50个随机数\n");
                print_arr(arr, n);
                counting_sort(arr, n);
                printf("计数排序后的数组: \n");
                print_arr(arr, n);
                test_sorting_time(counting_sort, "Counting", output_file);
                print_arr_to_file(output_file, arr, n);
                break;
            case 5:
                system("cls");
                srand(time(NULL));
                // 生成50个大于100的随机数
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 180 + 200; // 保证数大于100
                }
                printf("已生成50个随机数\n");
                print_arr(arr, n);
                radix_sort(arr, n);
                printf("基数排序后的数组: \n");
                print_arr(arr, n);
                test_sorting_time(radix_sort_adapter, "Radix", output_file);
                print_arr_to_file(output_file, arr, n);
                break;
            case 6:
                system("cls");
                printf("已退出程序。\n");
                exit(0);
            case 7:
                system("cls");
                printf("第一道题目答案如下\n");
                int arr1[] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };
                int n1 = sizeof(arr1) / sizeof(arr1[0]);

                sortArray(arr1, n1);

                for (int i = 0; i < n1; i++) {
                    printf("%d ", arr1[i]);
                }
                break;
            case 8:
                system("cls");
                printf("第二道题目答案如下\n");
                int arr2[] = { 5, 2, 8, 4, 3, 7, 6 };
                int n2 = sizeof(arr2) / sizeof(arr2[0]);
                int k = 4; // 数组索引从0开始，所以第3小的数索引为2
                quick_sort(arr2, 4, n2 - 1);
                printf("第3小的数是: %d\n", k);
                break;
            default:
                system("cls");
                printf("无效的选择,请重新输入操作\n");
                getchar();
               break;
            }
        }
        fclose(output_file);
        return 0;
    }



