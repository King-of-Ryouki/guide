// ! 結論：
// * 資料少   : 選擇排序(不穩定) > 插入排序(穩定)
// * 穩定     : 歸併排序(穩定)   > 插入排序(穩定)
// * 正常情況 : 快速排序(不穩定) > 歸併排序(穩定) > 堆積排序(空間 O(1))

// 快速排序 : 資料規模比較大，應用速度快，
// 當記錄隨機分佈的時候，快排的平均時間最短，但可能出現最壞的情況，
// 這時候的時間複雜度是O(n^2)，且遞迴深度為 n,所需的棧空間問 O(n)。

// （4）堆排序不會出現快排那樣的最壞情況，且堆排序所需的輔助空間比快排要少。
// （5）歸併排序可以用於內排序，也可以用於外排序。在外排序時，通常採用多路歸併，
//      並且通過解決長順串的合併，產生長的初始串，提高主機與外設並行能力等措施，以減少訪問外存額次數，提高外排序的效率。

else if // 時間複雜度
{
    // ! 速度排名(小到大)：
    // O(1)
    // O(log n)
    // O(n)
    // O(n log n)
    // O(n ^ 2)
    // O(2 ^ n)

    // O(1) // * 常數時間
    // * 永為 1 次
    // * e.g. array, if

    // O(n) // * 線性時間
    // * n 次
    // * e.g. for, 簡易搜尋

    // O(log n) // * 對數時間
    // ! log 都是以二為底, 16 = 2^4 ==> 4 = log(2) 16
    // * e.g. 二分搜尋法

    // O(n log n) // * 線性對數時間
    // * e.g. 合併排序, 最快的比較排序

    // O(n^2) // * 二次時間
    // * e.g. 氣泡排序, 插入排序, 選擇排序

    // O(2^n) // * 指數時間
    // * e.g. 費波那契數列
}

else if // 穩定與不穩定
{
    // * 穩定排序：
    // 氣泡排序
    // 插入排序
    // 歸併排序
    // 基數排序
    // 計數排序

    // * 不穩定排序：
    // 選擇排序
    // 快速排序
    // 希爾排序
    // 堆積排序
}

else if // 應用
{
    // 冒泡排序   垃圾
    // 雞尾酒排序 頭尾排好
    // 選擇排序   萬用，對比次數最多，移動次數最少。
    // 插入排序   適用於部分資料有序，有序部分越大越好。

    // 各種排序演算法的使用範圍總結：
    // （1）當資料規模較小的時候，可以用簡單的排序演算法如直接插入排序或直接選擇排序。
    // （2）當檔案的初態已經基本有序時，可以用直接插入排序或氣泡排序。
    // （3）當資料規模比較大時，應用速度快的排序演算法。可以考慮用快速排序。
    //      當記錄隨機分佈的時候，快排的平均時間最短，但可能出現最壞的情況，
    //      這時候的時間複雜度是 O(n^2)，且遞迴深度為 n,所需的棧空間問 O(n)。
    // （4）堆排序不會出現快排那樣的最壞情況，且堆排序所需的輔助空間比快排要少。
    //      但這兩種演算法都不是穩定的，若要求排序時穩定的，可以考慮用歸併排序。
    // （5）歸併排序可以用於內排序，也可以用於外排序。在外排序時，通常採用多路歸併，
    //      並且通過解決長順串的合併，產生長的初始串，提高主機與外設並行能力等措施，以減少訪問外存額次數，提高外排序的效率。

    // * 空間 O(1) (速度排名)
    // * 穩定排序：
    // 計數排序 O(n + m)                // 空間 O(n + m)
    // 歸併排序 O(n log n)              // 空間 O(n) + O(n log n)
    //
    // * 不穩定排序：
    // 快速排序 O(n log n) ~ O(n^2)     // 空間 O(log n) ~ O(n)
    // 堆積排序 O(n log n)              // 空間 O(1)

    // * 穩定排序與不穩定排序 (速度排名)
    // * 穩定排序：(常用)
    // 計數排序 O(n + m)                // 空間 O(n + m)
    // 歸併排序 O(n log n)              // 空間 O(n) + O(n log n)
    // 歸併排序 O(n log^2 n)            // 空間 O(1)
    // 基數排序 O(k*n) ~ O(n^2)         // 空間 未知
    // 插入排序 O(n^2)                  // 空間 O(1)
    // * 穩定排序：(不常用)
    // 氣泡排序 O(n^2)                  // 空間 O(1)
    //
    // * 不穩定排序：(常用)
    // 快速排序 O(n log n) ~ O(n^2)     // 空間 O(log n) ~ O(n)
    // 堆積排序 O(n log n)              // 空間 O(1)
    //
    // * 不穩定排序：(不常用)
    // 希爾排序 O(n log^2 n) ~ O(n^2)   // 空間 O(1)
    // 選擇排序 O(n^2)                  // 空間 O(1)
    //
    // k 代表數值中的"數位"個數
    // n 代表資料規模
    // m 代表資料的最大值減最小值

    // 快速排序 V.S 堆積排序
    // 简单来说，就是局部性原理。在堆排中，每一个操作都是不利于程序的局部性原理的，每次元素间的比较、数的调整等，
    // 都不是相邻或者尽可能附近的元素间的比较(堆调整每次都从堆底拿元素到堆顶然后向下进行调整），
    // 那么这就需要不断地在磁盘和内存间换入换出数据。
    // 反观快排，利用分而治之的方法，元素间的比较都在某个段内，局部性相当好哇。
}

else if // 排序
{
    else if // 冒泡排序(Bubble Sort)
    {
        // #include "../../_pch.hpp"

        // ******************************
        // *
        // * 冒泡排序(Bubble Sort)：
        // * 判斷的數字會優先移到最(頂/底)端
        // *
        // * 時間複雜度：
        // * 最壞時間複雜度 O(n^2)
        // * 最佳時間複雜度 O(n)
        // * 平均時間複雜度 O(n^2)
        // *
        // * 空間複雜度：
        // * 最壞空間複雜度 總共O(n) 輔助空間O(1)
        // *
        // ******************************

        // 冒泡排序，有時也被稱做沉降排序，是一種比較簡單的排序演算法。
        // 這種演算法的實現是透過遍歷要排序的列表，把相鄰兩個不符合排列規則的數據項交換位置，
        // 然後重複遍歷列表，直到不再出現需要交換的數據項。
        // 當沒有數據項需要交換時，則表明該列表已排序。

        template <typename T> // 若要使用類(class) 或結構體(struct) 時必須重載 ">"
        void BubbleSort(T arr[], int arr_size) {

            for (int i = 0; i < arr_size - 1; ++i) {
                bool is_swapped = false; // 判斷是否有交換，最佳解 O(n^2) => O(n)
                for (int j = 0; j < arr_size - 1 - i; ++j) {

                    if (arr[ j ] > arr[ j + 1 ]) {

                        std::swap(arr[ j ], arr[ j + 1 ]);
                        is_swapped = true;
                    }
                }

                if (is_swapped == false) { break; }
            }
        }

        // vector 迭代器
        template <typename T>                             // 若要使用類(class) 或結構體(struct) 時必須重載 ">"
        void BubbleSortVector(T iter_begin, T iter_end) { // T = vector<int>::iterator

            for (auto i = iter_begin; i != iter_end; ++i) {
                bool is_swapped = false;
                for (auto j = iter_begin; j != iter_end - 1; ++j) {

                    if (*j > *(j + 1)) {

                        swap(*j, *(j + 1));
                        is_swapped = true; // 表示此轮循环进行了交换
                    }
                }

                if (is_swapped == false) { break; }
            }
        }

        int main() {

            int arr_1[ 10 ] = { 1, 5, 8, 7, 9, 6, 4, 3, 2, 0 };
            int arr_1_size  = static_cast<int>(sizeof(arr_1) / sizeof(arr_1[ 0 ]));

            cout << "arr_1 : ";
            for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }

            cout << "\nBubbleSort       : ";
            BubbleSort(arr_1, arr_1_size);
            for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }

            vector<int> vec_1(arr_1, arr_1 + sizeof(arr_1) / sizeof(arr_1[ 0 ]));
            cout << "\nBubbleSortVector : ";
            BubbleSortVector(vec_1.begin(), vec_1.end());
            for (int i = 0; i < 10; ++i) { cout << vec_1[ i ] << ", "; }

            system("pause");
            return 0;
        }
    }

    else if // 雞尾酒排序
    {
        // #include "../../_pch.hpp"

        // ******************************
        // *
        // * 雞尾酒排序：
        // * 是氣泡排序的一種變形
        // * 不同處在於排序時是以雙向在序列中進行排序
        // *
        // * 時間複雜度：
        // * 最壞時間複雜度 O(n^2)
        // * 最佳時間複雜度 O(n)
        // * 平均時間複雜度 O(n^2)
        // *
        // ******************************

        // 雞尾酒排序，也就是定向氣泡排序，雞尾酒攪拌排序，攪拌排序（也可以視作選擇排序的一種變形），
        // 漣漪排序，來回排序或快樂小時排序，是氣泡排序的一種變形。
        // 此演算法與氣泡排序的不同處在於排序時是以雙向在序列中進行排序。

        // 雞尾酒排序等於是氣泡排序的輕微變形。不同的地方在於從低到高然後從高到低，
        // 而氣泡排序則僅從低到高去比較序列裡的每個元素。他可以得到比氣泡排序稍微好一點的效能，
        // 原因是氣泡排序只從一個方向進行比對（由低到高），每次循環只移動一個項目。
        //
        // 以序列(2,3,4,5,1)為例，雞尾酒排序只需要存取一次序列就可以完成排序，
        // 但如果使用氣泡排序則需要四次。但是在亂數序列的狀態下，雞尾酒排序與氣泡排序的效率都很差勁。

        template <typename T> // 若要使用類(class) 或結構體(struct) 時必須重載 ">"
        void CocktailSort(T arr[], int arr_size) {

            int i;
            int left  = 0;
            int right = arr_size - 1;

            while (left < right) {

                for (i = left; i < right; ++i) {
                    if (arr[ i ] > arr[ i + 1 ]) { swap(arr[ i ], arr[ i + 1 ]); } // * 大的往右
                }
                --right;

                for (i = right; i > left; --i) {
                    if (arr[ i - 1 ] > arr[ i ]) { swap(arr[ i - 1 ], arr[ i ]); } // * 小的往左
                }
                ++left;
            }
        }

        int main() {

            int arr_1[ 10 ] = { 1, 5, 8, 7, 9, 6, 4, 3, 2, 0 };
            int arr_1_size  = static_cast<int>(sizeof(arr_1) / sizeof(arr_1[ 0 ]));

            cout << "arr_1 : ";
            for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }

            CocktailSort(arr_1, arr_1_size);
            cout << "\nCocktailSort : ";
            for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }
            cout << endl;

            system("pause");
            return 0;
        }
    }

    else if // 插入排序(Insertion Sort)
    {
        // #include "../../_pch.hpp"

        // ******************************
        // *
        // * 插入排序(Insertion Sort)：
        // *
        // * 在已排序序列中從後向前掃描，找到相應位置並插入
        // *
        // * 時間複雜度：
        // * 最壞時間複雜度 O(n^2)
        // * 最佳時間複雜度 O(n)
        // * 平均時間複雜度 O(n^2)
        // *
        // * 空間複雜度：
        // * 最壞空間複雜度 O(1)
        // *
        // ******************************

        // 插入排序是一種簡單直觀的排序演算法。它的工作原理是通過構建有序序列，
        // 對於未排序資料，在已排序序列中從後向前掃描，找到相應位置並插入。插入排序在實現上，
        // 通常採用in-place排序（即只需用到 O(1) 的額外空間的排序），因而在從後向前掃描過程中，
        // 需要反覆把已排序元素逐步向後挪位，為最新元素提供插入空間。

        template <typename T> // 若要使用類(class) 或結構體(struct) 時必須重載 ">"
        void InsertionSort(T arr[], int arr_size) {

            for (int i = 0; i < arr_size - 1; ++i) {

                int i   = i;
                int tmp = arr[ i + 1 ];

                while ((i >= 0) &&
                       (arr[ i ]) > tmp) {

                    arr[ i + 1 ] = arr[ i ];
                    --i;
                }

                arr[ i + 1 ] = tmp;
            }
        }

        int main() {

            int arr_1[ 10 ] = { 1, 5, 8, 7, 9, 6, 4, 3, 2, 0 };
            int arr_1_size  = static_cast<int>(sizeof(arr_1) / sizeof(arr_1[ 0 ]));

            cout << "arr_1 : ";
            for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }

            InsertionSort(arr_1, arr_1_size);
            cout << "\nInsertionSort : ";
            for (int i = 0; i < arr_1_size; ++i) { cout << arr_1[ i ] << ", "; }
            cout << endl;

            system("pause");
            return 0;
        }
    }

    else if // 桶排序(Bucket sort)
    {
        // * 最壞時間複雜度 O(n^2)
        // * 平均時間複雜度 O(n+k)
        // * 最壞空間複雜度 O(n*k)

        // 桶排序（Bucket sort）或所謂的箱排序，是一個排序演算法，工作的原理是將陣列分到有限數量的桶裡。
        // 每個桶再個別排序（有可能再使用別的排序演算法或是以遞迴方式繼續使用桶排序進行排序）。
        // 桶排序是鴿巢排序的一種歸納結果。當要被排序的陣列內的數值是均勻分配的時候，桶排序使用線性時間 O(n)。
        // 但桶排序並不是比較排序，他不受到 O(n log n)下限的影響。

        // 桶排序以下列程式進行：
        //
        // 設定一個定量的陣列當作空桶子。
        // 尋訪序列，並且把項目一個一個放到對應的桶子去。
        // 對每個不是空的桶子進行排序。
        // 從不是空的桶子裡把項目再放回原來的序列中。

        // ! vvvvv e.g. 桶排序(Bucket sort) vvvvv

        // data : 5 6 8 20 12 21 -----

        //     |  5  |    |     |    |     |
        //     |  6  |    |     |    |  20 |
        //     |  8  |    |  12 |    |  21 |
        //     |_____|    |_____|    |_____|
        //       0~9      10~19     20~29

        // ! ^^^^^ e.g. 桶排序(Bucket sort) ^^^^^
    }
}

else // 搜尋
{
}