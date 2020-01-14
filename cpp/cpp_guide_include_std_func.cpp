if // cin endl 解綁, 加速输入輸出
{
    // cin endl 解綁, 加速输入輸出
    static int cin_cout_speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }(); // cin endl 解綁, 加速输入輸出
    // or ----------
    int main() {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);

        return 0;
    }

    // sync_with_stdio
    // 这个函数是一个 "是否兼容stdio" 的开关，C++为了兼容C，保证程序在使用了std::printf和std::cout的时候不发生混乱，将输出流绑到了一起。

    // 在默认的情况下cin绑定的是cout，每次执行 << 操作符的时候都要调用flush，这样会增加IO负担。
    // 可以通过tie(0)（0表示NULL）来解除cin与cout的绑定，进一步加快执行效率。
}

else if // #include <ctime> // 日期和時間
{
}

else if // #include <iostream> // 該文件定義了 cin、cout、cerr 和 clog 對象，分別對應於標準輸入流、標準輸出流、非緩衝標準錯誤流和緩衝標準錯誤流。
{
    // #include <iostream>
    using std::cin;
    using std::cout;
    using std::endl;
}

else if // #include <iomanip> // 該文件通過所謂的參數化的流操縱器（比如 setw 和 setprecision），來聲明對執行標準化 I/O 有用的服務。
{
    // #include <iomanip>
    setfill(5); // 前面補5個空格
}

else if // #include <fstream> // 該文件為用戶控制的文件處理聲明服務。我們將在文件和流的相關章節討論它的細節。
{
    // #include <fstream>
}

else if // #include <stdio.h>
{
    // #include <stdio.h>
    FILE f;
}

else if // #include <windows.h> // 鍵盤輸出入 && 計時
{
    else if // 鍵盤輸出入
    {
        // #include <windows.h>
        // GetAsyncKeyState(VK_) // 鍵盤輸出入
    }

    else if // 計時
    {
        // #include <windows.h> // QueryPerformanceFrequency, QueryPerformanceCounter

        // using std::cout;
        // using std::endl;

        int main() {

            LARGE_INTEGER nFreq;
            LARGE_INTEGER t1;
            LARGE_INTEGER t2;

            QueryPerformanceFrequency(&QueryPerformanceFrequency);

            QueryPerformanceCounter(&t1); // 開始計時

            // ! vvvvv code begin vvvvv

            Sleep(200);

            // ! ^^^^^ code end   ^^^^^

            QueryPerformanceCounter(&t2); // 結束計時

            // * 耗時
            double spend_time = 1000 * // ! 1000 == ms, 1000000 == us
                                (t2.QuadPart - t1.QuadPart) /
                                static_cast<double>(QueryPerformanceFrequency.QuadPart);
            cout << "spend time : " << spend_time << "ms" << endl;

            system("pause");
            return 0;
        }
    }
}

else if // #include <stdlib.h> // C 語言動態記憶體配置的相關函數
{
}

else if // getline()
{
    // 在C++中本質上有兩種getline函數，一種在頭文件<istream>中，是istream類的成員函數。
    // 一種在頭文件<string>中，是普通函數。

    // 第一種:  在<istream>中的getline()函數有兩種重載形式:
    istream &getline(char *s, streamsize n);
    istream &getline(char *s, streamsize n, char delim);

    // 作用是:  從istream中讀取至多n個字符(包含結束標記符)保存在s對應的數組中。即使還沒讀夠n個字符，
    // 如果遇到delim或 字數達到限制，則讀取終止，delim�m不會被保存進s對應的數組中。

    // 第二種:  在<string>中的getline函數有四種重載形式:
    istream &getline(istream & is, string & str, char delim);
    istream &getline(istream && is, string & str, char delim);
    istream &getline(istream & is, string & str);
    istream &getline(istream && is, string & str);

    // 用法和上第一種類似，但是讀取的istream是作為參數is傳進函數的。讀取的字符串保存在string類型的str中。
    // 函數的變量:
    // is : 表示一個輸入流，例如cin。
    // str : string類型的引用，用來存儲輸入流中的流信息。
    // delim : char類型的變量，所設置的截斷字符；在不自定義設置的情況下，遇到’\n’，則終止輸入。
}

else if // cin.ignore()
{
    // 功能: 用於輸入流。它讀入字符，直到已經讀了num 個字符(默認為1)或是直到字符delim 被讀入(默認為EOF) 其調用形式為cin.ignore(n,終止字符)
    // 原型: istream &ignore( streamsize num=1, int delim=EOF );
    // EOF 會清掉前一個字元
    // 函數作用是跳過輸入流中n個字符，或在遇到指定的終止字符時提前結束 (此時跳過包括終止字符在內的若干字符)
    // cin.ignore(); 不帶參數默認為1

    int main() {
        char array[ 8 ];
        cin.ignore(6, 'a');
        cin.getline(array, 8);
        cout << array << endl;
        // 輸入：bcdefgk 輸出：k
        // 輸入：bcagkld 輸出：gkld

        return 0;
    }

    cin.ignore(1024, '\n'); // 把第一個參數設置得足夠大，這樣實際上總是只有第二個參數'\n'��作用
}

else if // GetAsyncKeyState()
{
    // GetAsyncKeyState是一個用來判斷函數調用時指定虛擬鍵的狀態，確定用戶當前是否按下了鍵盤上的一個鍵的函數。如果按下，則返回值最高位為1
    // 返回值 short
    // 自對GetAsyncKeyState函數的上一次調用以來，如鍵已被按過，則位0設為1；否則設為0。
    // 如鍵目前處於按下狀態，則位15設為1；如抬起，則為0。
    // 倘若輸入焦點從屬於與調用函數的輸入線程不同的另一個輸入線程，則返回值為0（例如，一旦另一個程序擁有焦點，則它應返回零）。
    // 證據顯示，函數實際是在整個系統的範圍內工作的。

    // 函數名 返回值類型 備註
    // GetAsyncKeyState SHORT 用來判斷函數調用時指定虛擬鍵的狀態
    // 參數 類型 說明
    // vKey int 欲測試的虛擬鍵的鍵碼

    // GetAsyncKeyState 函數功能:
    // 該函數判斷在此函數被調用時,某個鍵是處於UP狀態還是處於DOWN狀態,
    // 及前次調用GetAsyncKeyState函數後,是否按過此鍵.如果返回值的最高位被置位,
    // 那麼該鍵處於DOWN狀態;如果最低位被置位,那麼在前一次調用此函數後,此鍵被按過,否則表示該鍵沒被按過.

    // 應用程序可以使用虛擬鍵碼常數VK_SHIFT，VK_CONTROL和VK_MENU作為nVirtKey參數的值。
    // 它給出shift，ctrl或alt鍵的值而不區分左右鍵，應用程序也可以使用如下的虛擬鍵碼常數作nVirtKey的值來區分前述鍵的左鍵、右鍵的情形。

    // 常用鍵的VK值：
    // VK_SHIFT Shift鍵
    // VK_LSHIFT 左Shift鍵
    // VK_RSHIFT 右Shift鍵
    // VK_CONTROL Ctrl鍵
    // VK_LCONTROL 左Ctrl鍵
    // VK_RCONTROL 右Ctril鍵
    // VK_MENU Alt鍵
    // VK_LMENU 左Alt鍵
    // VK_RMENU 右Alt鍵
    // VK_LBUTTON 鼠標左鍵
    // VK_RBUTTON 鼠標右鍵
    // VK_ESCAPE ESC鍵
    // VK_RETURN 回車鍵
    // VK_TAB TAB鍵
    // VK_SPACE 空格鍵
    // VK_UP ↑鍵
    // VK_DOWN ↓鍵
    // VK_LEFT ←鍵
    // VK_RIGHT →鍵

    // 另一個函數GetKeyState與GetAsyncKeyState函數不同。 GetAsyncKeyState在按下某鍵的同時調用，判斷正在按下某鍵。
    // GetKeyState則在按過某鍵之後再調用，它返回最近的鍵盤消息從線程的隊列中移出時的鍵盤狀態，判斷剛按過了某鍵。

    // GetAsyncKeyState 取異步鍵狀態。
    // 比如，一般情況下，你可以在操作系統的控制面板中設置鼠標左右鍵的映射（實際的鼠標左鍵可以映射成右鍵點擊事件），
    // 或者通過程序也可以這樣設置，這樣就產生了物理鍵狀態（實際的），邏輯鍵狀態（虛擬的，）。
    // 使用 GetKeyState,GetKeyboardState,等函數得到的就是邏輯鍵狀態。
    // 而 GetAsyncKeyState 讀取的是物理鍵狀態，也是就是不管你怎麼鼠標鍵盤映射，它只讀取實際的按鍵狀態。
}

else if // sort // 排序
{
    // https://blog.csdn.net/zzzmmmkkk/article/details/4266888
    // #include <algorithm>

    // sort                 对给定区间所有元素进行排序
    // stable_sort	        对给定区间所有元素进行稳定排序
    // partial_sort	        对给定区间所有元素部分排序
    // partial_sort_copy    对给定区间复制并排序
    // nth_element	        找出给定区间的某个位置对应的元素
    // is_sorted	        判断一个区间是否已经排好序
    // partition	        使得符合某个条件的元素放在前面
    // stable_partition	    相对稳定的使得符合某个条件的元素放在前面
}

else if // #include <algorithm> // reverse 字串反轉 // min_element, max_element 返回範圍內的最大(小)元素
{
    if // reverse 字串反轉
    {
        int a[ 10 ] = {};
        for (int i = 0; i < 10; ++i) { a[ i ] = i; } // 0 ~ 9

        reverse(a, a + 5);           // 4 3 2 1 0 5 6 7 8 9 // 0 ~ 5 反轉
        reverse(a.begin(), a.end()); // 9 8 7 6 5 4 3 2 1 0 // 頭尾反轉
    }

    else if // max_element, min_element 返回範圍內的最大(小)元素
    {
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());
    }
}

else if // #include <stddef.h> // size_t
{
    // * 用途
    // array 長度
    // sizeof
}

else if // #include <limits> // numeric_limits 求類型上限
{
    // #include <limits>

    int main() {
        cout << "type  : ************size**************" << endl;
        cout << "bool  : 所占字节数 : " << sizeof(bool) << endl;
        cout << "最大值 : " << (numeric_limits<bool>::max)();
        cout << "最小值 : " << (numeric_limits<bool>::min)() << endl;
    }
}
