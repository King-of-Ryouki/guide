// C++ 基礎 語法

int guide_cpp = 1;

if (guide_cpp) // 編譯
{

    // -c // 編譯
    // -o // 連接

    // cd E:\program\src\practice\game\2048\cpp\game_2048_console_version
    // g++ -o game_2048_console_version main.cpp keyboard_input.cpp game_view.cpp

    // g++ -c main.cpp keyboard_input.cpp game_view.cpp
    // g++ -o game_2048_console_version main.o keyboard_input.o game_view.o

    // gcc -E hello.c -o hello.i // 编译
    // gcc -S hello.i -o hello.s // 汇编
    // gcc -c hello.s -o hello.o // 链接
    // gcc hello.o -o hello

    // * -----

    // $ g++ -c main.cpp            // 產出 main.o
    // $ g++ -c a.cpp               // 產出 a.o
    // $ g++ -c b.cpp               // 產出 b.o
    // $ g++ -o main main.o a.o b.o // 把 main.o, a.o, b.o link 成 main
}

if (guide_cpp) // 數據類型
{

    bool;    // 布爾型
    char;    // 字符型
    int;     // 整型
    float;   // 浮點型   1位符號， 8位指數，23位小數。
    double;  // 雙浮點型 1位符號，11位指數，52位小數。
    void;    // 無類型
    wchar_t; // 寬字符型

    signed;
    unsigned; // 正值
    short;    // int / 2
    long;     // int * 2
}

if (guide_cpp) // 存储类
{

    // auto
    // register
    // static
    // extern
    // mutable
    // thread_local // C++11
}

if (guide_cpp) // 輸出入
{

    if (guide_cpp) // 輸入
    {

        // 三个都是C++中的输入函数，不同点在于
        // cin<<的结束符有enter space tab
        // cin.get()的结束符只有enter，但会把enter放入队列等待
        // cin.getline()的结束符也只有enter，但不会把enter放入队列

        // >> 是会过滤掉不可见字符（如 空格 回车，TAB 等）
        // 接受一个字符串，遇“空格”、“TAB”、“回车”都结束
        int a, b;
        cin >> a >> b;
        // 输入：jkljkl jkljkl // 遇空格结束
        // 输出：jkljkl

        // 不想略过空白字符，那就使用 noskipws 流控制
        cin >> noskipws >> input[ j ];

        if // cin.get(); & cin.getline();
        {
            // cin.get(array_name, Arsize)当输入的字符串超长时，不会引起下一個cin函数輸入的错误，
            // 后面的cin操作会继续执行，只是直接从缓冲区中取数据。且不会丢弃最后的Enter字符。
            // 但是cin.getline()当输入超长时，会引起下一個cin函数輸入的错误，后面的cin操作将不再执行。

            // !----------
            // cin.get();
            // 用法1： cin.get(字符变量名)可以用来接收字符
            char ch;
            ch = cin.get(); // 或者cin.get(ch);
            cout << ch << endl;
            // 输入：jljkljkl
            // 输出：j

            // 用法2：cin.get(字符数组名,接收字符数目)用来接收一行字符串,可以接收空格
            char a[ 20 ];
            cin.get(a, 20);
            cout << a << endl;
            // 输入：abcdeabcdeabcdeabcdeabcde // （输入25个字符）
            // 输出：abcdeabcdeabcdeabcd       // （接收19个字符+1个'\0'）

            // !----------
            // 类似
            getline();     // string
            cin.getline(); // istream

            // cin.getline(); // 接受一个字符串，可以接收空格并输出
            char m[ 20 ];
            cin.getline(m, 5);
            cout << m << endl;
            // cin.getline(); // 实际上有三个参数
            // cin.getline(接受字符串, 接受个数, 结束字符);

            // 当第三个参数省略时，系统默认为'\0'

            // 如果将例子中cin.getline()改为cin.getline(m,5,'a');
            // 输入jlkjkljkl 输出 jklj
            // 输入jkaljkljkl 时，输出 jk

            // !----------
            string str;
            getline(cin, str);
        }
    }

    if (guide_cpp) // 錯誤輸出
    {
        cerr << "cerr" << endl; // cerr 不經過緩衝區
        clog << "clog" << endl; // clog 中的信息存放在緩衝區
    }

    if (guide_cpp) // 清除緩衝區
    {
        cout << fflush;
        cin >> fflush;

        cin.clear();       // 更改 cin 的状态标示符，防止進入死循環
        cin.sync();        // 清除缓存区的数据流
        cin.ignore(a, ch); // 从输入流（cin）中提取字符，提取的字符被忽略（ignore），不被使用。
                           // 每抛弃一个字符，它都要计数和比较字符：如果计数值达到a或者被抛弃的字符是ch

        // !v| e.g. 清空緩衝區 -----

        // #include "_pch.hpp"

        int main() {

            int var_1;

            cout << "input var_1 : " << endl;
            cin >> var_1;          // * input : 123 456 789
            cout << var_1 << endl; // 123

            cin >> var_1;          // error ==> 456
            cout << var_1 << endl; // 456

            cin.clear(); // * 清除輸入錯誤
            cin.sync();  // * 清除緩衝區

            cin >> var_1;          // 沒有 cin.sync(); ==> error ==> 789
            cout << var_1 << endl; // 沒有 cin.sync(); ==> 789

            system("pause");
            return 0;
        }

        // !^| e.g. 清空緩衝區 -----
    }
}

if (guide_cpp) // # & ## // 預編譯
{
    if (guide_cpp) // # if 控制
    {

        // #if               // 可當區塊註解使用
        // #define control 0 // 0為註解 1為顯示
        // #if control       // 0為註解 1為顯示
        // #elif control     // 下一行放程式碼
        // #else             // 下一行放程式碼
        // #endif            // 結束
    }
}

if (guide_cpp) // volatile (用於多線程)
{
    if (guide_cpp) // volatile 用法
    {
        // volatile 修飾符 volatile 告訴編譯器，變量的值可能以程序未明確指定的方式被改變。
        // restrict 由 restrict 修飾的指針是唯一一種訪問它所指向的對象的方式。只有 C99 增加了新的類型限定符 restrict。

        // 告訴compiler, *pPort變數具有揮發性的特性,
        // 所以與它有關的程式碼請不要作最佳化動作, 因而 i = *pPort;
        // volatile U8 *pPort;
        U8 *pPort;
        U8 i, j, k;
        i = *pPort;
        j = *pPort;
        k = *pPort;
        i = j = k = *pPort; // *pPort讀取一次, 而產生 i = j = k 的結果, 改為
    }

    if (guide_cpp) // volatile 用於多線程
    {
        volatile boolean isNext = false;

        Thread A() {
            // 第一個工作
            // isNext = true;
        }

        Thread B() {
            if (isNext) {
                // 第二個工作
            }
        }
    }
}

if (guide_cpp) // 常量 變數名全大寫
{
    if // 整數常量
    {
        // 整數常量可以是十進制、八進製或十六進制的常量。前綴指定基數：0x 或 0X 表示十六進制，
        // 0 表示八進制，不帶前綴則默認表示十進制。
        // 整數常量也可以帶一個後綴，後綴是 U 和 L 的組合，U 表示無符號整數（unsigned），
        // L 表示長整數（long）。後綴可以是大寫，也可以是小寫，U 和 L 的順序任意。

        // #define a 0 // 無類型,屬於全域
        // #undef a    // 取消常量

        const int a = 3;   // const 唯讀,不可變更
        register int a;    // 存在暫存器
        static int a = 10; // 全域變數限定本文件使用，或是函數內一次使用

        extern int a; // 編譯時自動尋找
        a = 0;
    }
}

if (guide_cpp) // 轉換 & 轉型
{
    if (guide_cpp) // 轉型
    {
        static_cast<int>(var_1);  // 無類型檢查
        dynamic_cast<int>(var_2); // 有類型檢查
    }

    if (guide_cpp) // 隱性(implicit) 轉換跟 顯性(explicit) 轉換
    {
        if // 顯性 (explicit)
        {
            class Test1 {
            public:
                Test1(int var_1) { var_1_ = var_1; }

            private:
                int var_1_;
            };

            class Test2 {
            public:
                explicit Test2(int var_1) { var_1_ = var_1; } // explicit(顯式)構造函數

            private:
                int var_1_;
            };

            int main() {
                Test1 t1 = 12; // 隱式調用其構造函數,成功 Test1(int var_1)
                Test2 t2 = 12; // 編譯錯誤,不能隱式調用其構造函數 explicit Test2(int var_1)

                Test2 t2(12); // 顯式調用成功

                system("pause");
                return 0;
            }
        }

        if (guide_cpp) // 顯性2 (explicit)
        {
            class MyClass {
            public:
                MyClass(int var_1_); // 前面加上 explicit, 會 err, can't non-explict convert
            } MyClass obj = 10;      // ok, convert int to MyClass

            // 等同
            MyClass temp(10);
            MyClass obj = temp;
        }
    }
}

if (guide_cpp) // typedef
{
    if // typedef 基礎用法
    {
        typedef int test; // test 等同 int
        test a;           // 等同 int a

        typedef long int *pliType;
        pliType x, y, z; // long int 型別指標

        // typedef 指標
        typedef char *PCHAR; // char指標
        PCHAR pa, pb;        // 等同 char *pa, *pb; 而非 char *pa, pb;
    }

    if (guide_cpp) // typedef 給舊代碼
    {
        typedef struct tagPOINT {
            int x;
            int y;
        } POINT;

        POINT p1;
    }

    if (guide_cpp) // typedef 平台差異
    {
        typedef long double REAL;

        // 在不支持long double的平台上，改為：
        typedef double REAL;

        // 在連double 不支持的平台上，改為：
        typedef float REAL;
    }
}

if (guide_cpp) // string 字符串
{
    // #include <string>

    // string 字符串
    string str("abcdef");

    assign(string, start, num); // 從string的第start個字元取出num個字元來指定給另一字串物件。
    append(string, start, num); // string 字元附加
    replace();                  // 替換字符串
    insert(start, string);      // 將string插入引發insert的字串物件第start個字元之後。
    length();                   // 傳回字串的長度。
    str.find(string, 0);        // 從引發find的字串物件第0個字元尋找是否有符合string的子字串。
    str.substr(2, 3);           // 返回某個子字符串 // ab(cde)
    strcpy(str1, str2);         // 複製字符串 str2 到字符串 str1。
    strcat(str1, str2);         // 連接字符串 str2 到字符串 str1 的末尾。
    strlen(str1);               // 返回字符串 str1 的長度。
    strcmp(str1, str2);         // 如果 str1 和 str2 是相同的，則返回 0；如果 str1<str2 則返回值小於 0；如果 str1> str2 則返回值大於 0。
    strchr(str1, ch);           // 返回一個指針，指向字符串 str1 中字符 ch 的第一次出現的位置。
    strstr(str1, str2);         // 返回一個指針，指向字符串 str1 中字符串 str2 的第一次出現的位置。

    // ! -----
    str.append(string, start, num); // string 字元附加
    // 直接添加另一个完整的字符串:
    str1.append(str2);
    // 添加另一个字符串的某一段子串:
    str1.append(str2, 11, 7);
    // 添加几个相同的字符:
    str1.append(5, '.');

    // ! -----
    string str[] = { "test.email+alex@leetcode.com",
                     "test.e.mail+bob.cathy@leetcode.com",
                     "testemail+david@lee.tcode.com" };
    vector<string> nums(str, str + 3);

    cout << nums[ 1 ][ 2 ] << endl; // s
}

if (guide_cpp) // 運算
{
    if // 運算元
    {
        var = (a = 19, b = 10, a + 1); // 運算完只傳最右邊的值 var = 19 + 1;

        int *ptr = &a; // 指標
    }

    if (guide_cpp) // 布林運算
    {
        (a && b);  // 都非零 為真
        (a || b);  // 一個非零 為真
        !(A && B); // ! 真假反轉

        // 2進位
        // & AND
        // | OR
        // ^ 僅出現一次 1011 1100 > 0111
        // ~ 01互轉
        // a << 4 左移4位 0000 1110 >> 1110 0000
        // a >> 4 右移4位 1110 0000 >> 0000 1110
    }

    if (guide_cpp) // 數學運算
    {
        double cos(double);           // 返回弧度角（double 型）的餘弦。
        double sin(double);           // 返回弧度角（double 型）的正弦。
        double tan(double);           // 返回弧度角（double 型）的正切。
        double log(double);           // 返回參數的自然對數。
        double pow(double, double);   // 假設第一個參數為 x，第二個參數為 y，則該函數返回 x 的 y 次方。
        double sqrt(double);          // 返回參數的平方根。
        double hypot(double, double); // 返回兩個參數的平方總和的平方根，也就是說,
        // 參數為一個直角三角形的兩個直角邊，函數會返回斜邊的長度。
        double floor(double); // 返回一個小於或等於傳入參數的最大整數。
        int abs(int);         // 返回整數的絕對值。
        double fabs(double);  // 返回任意一個十進制數的絕對值。
    }

    if (guide_cpp) // 日期和時間 #include <ctime>
    {
        if // 結構類型
        {
            // 有四個與時間相關的類型：clock_t、time_t、size_t 和 tm。
            // 類型 clock_t、size_t 和 time_t 能夠把系統時間和日期表示為某種整數。
            // 結構類型 tm 把日期和時間以 C 結構的形式保存，tm 結構的定義如下:

            struct tm {
                int tm_sec;   // 秒，正常範圍從 0 到 59，但允許至 61
                int tm_min;   // 分，範圍從 0 到 59
                int tm_hour;  // 小時，範圍從 0 到 23
                int tm_mday;  // 一月中的第幾天，範圍從 1 到 31
                int tm_mon;   // 月，範圍從 0 到 11
                int tm_year;  // 自 1900 年��的年數
                int tm_wday;  // 一周中的第幾天，範圍從 0 到 6，從星期日算��
                int tm_yday;  // 一年中的第幾天，範圍從 0 到 365，從 1 月 1 日算��
                int tm_isdst; // 夏令時
            }
        }

        if (guide_cpp) // 系統時間
        {
            time_t time(time_t * time);                  // 返回系統的當前日曆時間，自 1970 年 1 月 1 日以來經過的秒數。如果系統沒有時間，則返回 .1。
            char *ctime(const time_t *time);             // 該返回一個表示當地時間的字符串指針，字符串形式 day month year hours:minutes:seconds year\n\0。
            struct tm *localtime(const time_t *time);    // 返回一個指向表示本地時間的 tm 結構的指針。
            clock_t clock(void);                         // 返回程序執行��（一般為程序的開頭），處理器時鐘所使用的時間。如果時間不可用，則返回 .1。
            char *asctime(const struct tm *time);        // 返回一個指向字符串的指針，字符串包含了 time 所指向結構中存儲的信息，返回形式為：day month date hours:minutes:seconds year\n\0。
            struct tm *gmtime(const time_t *time);       // 返回一個指向 time 的指針，time 為 tm 結構，用協調世界時（UTC）也被稱為格林尼治標準時間（GMT）表示。
            time_t mktime(struct tm * time);             // 返回日曆時間，相當於 time 所指向結構中存儲的時間。
            double difftime(time_t time2, time_t time1); // 返回 time1 和 time2 之間相差的秒數。
            size_t strftime();                           // 可用於格式化日期和時間為指定的格式。
        }
    }
}

if (guide_cpp) // 迴圈 & 判斷 // if & for & switch & while & recursive
{
    if (guide_cpp) // if (三目運算符 法則由右至左)
    {
        // ! e.g. if else -----
        if (y < 10) {
            x = 30;
        } else {
            x = 40;
        }

        // ! e.g. 三目運算符 -----
        x = (y < 10) ? 30 : 40; // 等價
    }

    if (guide_cpp) // for 迴圈 // * 用於次數或範圍(基於範圍)
    {
        // !v| e.g. 用於次數 -----

        for (int i = 10; i < 15; i += 1) {
            cout << "i 的值：" << i << endl; // 10 ~ 14
        }

        // !^| e.g. 用於次數 -----

        // !v| e.g. 用於範圍(基於範圍) -----

        int array[] = { 1, 2, 3, 4, 5 }; // 陣列*2

        for (int &x : array) {

            x *= 2;

            cout << x << endl;
        }

        // !^| e.g. 用於範圍(基於範圍) -----

        // !v| e.g. 迴圈中跳出或返回判斷式 -----

        for (int i = 0; i < 10; ++i) {

            if (i < 5) { continue; } // 後面不做 跳回迴圈

            cout << i << endl; // ! res : 5 6 7 8

            if (i == 8) { break; } // 跳出
        }

        // !^| e.g. 迴圈中跳出或返回判斷式 -----
    }

    if (guide_cpp) // while 迴圈 // * 用於條件
    {
        while (i < 20) // 10 ~ 19 跳出
        {
            cout << "i 的值：" << i << endl;
            ++i;
        }
    }

    if (guide_cpp) // do while 迴圈 // * 用於條件
    {
        // 跟 while 相比，一定會先做一次
        do {
            cout << "var of i : " << i << endl;
            ++i;
        } while (i < 20); // 10 ~ 19 跳出
    }

    if (guide_cpp) // recursive 遞迴
    {
        int RecursiveSum(int var_1) {
            return (var_1 <= 0) ? 0 : (var_1 + RecursiveSum(var_1 - 1));
        }
    }

    if (guide_cpp) // switch
    {
        char var_1 = 'A';

        switch (var_1) // (整數 列舉 class)
        {
            case 'A': cout << "A" << endl; break;
            case 'B': cout << "B" << endl; break;

            default: cout << "C" << endl;
        }
    }
}

if (guide_cpp) // 參考/引用(&) (reference) 與 指標(*) (pointer)
{
    if // 參考 (reference)
    {
        // 不存在空參考。參考必須連接到一塊合法的內存。
        // 一旦參考被初始化為一個對象，就不能被指向到另一個對象。指標可以在任何時候指向到另一個對象。
        // 參考必須在創建時被初始化。指標可以在任何時間被初始化。
        int &ptr = var_1; // &參考

        // 參考 (reference)一定要被同型別的物件給初始化。
        // 一旦初始化，無法重新綁定至另一個物件。

        // 必須要 reference to const 才能參照一個 const 物件。
        const int var_1  = 38;
        const int &ref_1 = var_1; // 正確
        int &ref_2       = var_1; // 錯誤

        // 必須要 reference to const 才能指向一個字面常數。
        const int &ref_1 = 50;

        // 可以 reference to 一個 pointer
        int var_1   = 10;
        int *ptr_1  = &var_1;
        int *&ref_1 = ptr_1;
    }

    if (guide_cpp) // 指標 (pointer)
    {
        // 未使用的指標請賦予空值
        int *ptr = 0;
        int *ptr = nullptr;

        // pointer 存放特定物件的位址，或某物件尾端的下一位置，為零表示不指向任何物件：
        int var_1  = 1024;
        int *ptr_1 = &var_1; // pi2內含ival的位址。
        int *ptr_2 = ptr_1;  // pi3和pi2指向同一個物件ival。

        // 除了void * 的 pointer 型別，其他必須型別吻合：
        void *ptr_1 = &obj; // obj可以是任何型別

        // void *pointer 可以將它傳給函式，或讓函式返回它，但不能操作它所指的物件。
        string s   = "hello";
        string *sp = &s;
        *sp        = "world"; // 改變所指物件的值
        string s2  = "some value";
        sp         = &s2 // 將sp指向其他物件
    }

    if (guide_cpp) // const 指標
    {
        // pointer to const & const point
        //
        // pointer to const 是指向一個常數的 pointer,
        // const point 是個常數 pointer ,
        // 所以不能更改指向物件(因為代表值的位址不能更改)

        // 必須要 pointer to const 才能參照一個 const 物件。
        const int ival  = 38;
        const int *cptr = &ival; // 正確
        int *ptr        = &ival; // 錯誤

        // pointer to const 可賦予一個 nonconst 的物件位址：
        int ival        = 38;
        const int *cptr = &ival; // 正確，但不能透過 cptr 修改 ival 的值，否則會導致錯誤。

        // const pointer 不能改變所指物件：
        int someNum    = 20;
        int otherNum   = 30;
        int *const ptr = &someNum;  // ptr 是個 const pointer
        ptr            = &otherNum; // 錯誤
    }
}

if (guide_cpp) // 函數
{
    if (guide_cpp) // 函數 外置
    {
        //   #include "_pch.hpp"

        int MaxVal(int var_1, int var_2);

        int main() {

            cout << MaxVal(10, 20) << endl;

            system("pause");
            return 0;
        }

        int MaxVal(int var_1, int var_2) { return (var_1 > var_2) ? var_1 : var_2; }
    }

    else // 函數 Lambda, 可使用 this 指標
    {
        // 但[]要使用 this 指標，必須顯式傳入：
        int Lambda = [this]() { this->someFunc(); }();
        int Lambda = [](int a, int b) { return a < b; };
        int Lambda = [] { ++global_x; };
        int Lambda = [](int x, int y) -> int { int z = x + y; return z + x; };
        // []     沒有定義任何變量。使用未定義變量會引發錯誤。
        // [x,&y] x以傳值方式傳入（默認），y以參考方式傳入。
        // [=]    任何被使用到的外部變量 隱式地以傳值方式加以參考。
        // [&]    任何被使用到的外部變量 隱式地以參考方式加以參考。
        // [&,x]  x顯式地以傳值方式加以參考。其餘變量以參考方式加以參考。
        // [=,&z] z顯式地以參考方式加以參考。其餘變量以傳值方式加以參考。
    }
}

if (guide_cpp) // enum 列舉 & struct 結構體
{
    if (guide_cpp) // 列舉
    {
        if (guide_cpp) // 列舉
        {
            // #include "../../_pch.h"

            enum ENUM_COLOR {
                red,       // 值為 0
                green = 5, // 值為 5
                blue       // 值為 6
            };

            int main() {

                ENUM_COLOR ENUM_COLOR;
                ENUM_COLOR = blue;
                cout << ENUM_COLOR << endl; // ! res : 6

                system("pause");
                return 0;
            }
        }

        if (guide_cpp) // 列舉陣列
        {
            // #include "../../_pch.h"

            enum ENUM_LANGUAGE {

                language_en = 0,
                language_us,

                language_unknown,

            };

            int main() {

                ENUM_LANGUAGE ENUM_LANGUAGE;
                ENUM_LANGUAGE = language_us;

                static const char *language_type[] = {
                    [language_en] = "Chinese",
                    [language_us] = "American"
                };

                cout << language_type[ language_en ] << endl; // ! res : Chinese

                system("pause");
                return 0;
            }
        }
    }

    if (guide_cpp) // struct 結構
    {
        if // 結構
        {
            // class  默認 private
            // struct 默認 public

            // 舉個實例來說，可以定義一個「球」的模子，考慮球有各種不同的顏色，以及球最基本的球半徑資訊，
            // 若這組資料經常在一起出現，這些資訊應該可以定義一個 Ball 型態，在 C 中要包裝這些資訊時，可以如下進行定義：

            // !v| e.g. 賦值 -----

            struct Struct_Ball {
                double var_1;
                double var_2;
            };

            int main() {
                struct Struct_Ball Ball_1;
                Ball_1.var_2 = 5.0;

                // 指定初始化 (Designated Initializer) 实现上有两种方式，一种是通过点号加赋值符号实现，
                // 即".fieldname=value" 另外一种是通过冒号实现，
                // 即" fieldname:value" 其中 fieldname 为结构体成员名称。
                // 前一种是C99 标准引入的结构体初始化方式，但在 C++ 中，很多编译器并不支持。

                struct Struct_Ball Ball_2 {
                    .var_1 = 1.0,
                    .var_2 = 5.0, // 最後一個不一定要加(,)
                };

                struct Struct_Ball Ball_3 {
                    var_1 : 1.0,
                        var_2 : 5.0, // 最後一個不一定要加(,)
                };

                struct Struct_Ball Ball_4 {
                    1.0,
                        5.0,
                };

                // 使用 memset 对结构体变量进行置空操作：
                //按照编译器默认的方式进行初始化（如果 a 是全局静态存储区的变量，默认初始化为0，如果是栈上的局部变量，默认初始化为随机值）
                struct Struct_Ball Ball_5;
                memset(&Ball_5, 0, sizeof(Ball_5));
                // 或
                memset(this, 0, sizeof(Ball_5));

                system("pause");
                return 0;
            }

            // !^| e.g. 賦值 -----

            // 這樣的話，ball1 將包括 color 與 radius 兩個資料成員，以上的寫法將 color 成員初始化為 "red"，而 radius 初始化為 5.0；也可以先宣告，後來再設定成員資料，例如：
            struct Struct_Ball ball2;
            strcpy(ball2.color, "green");
            ball2.radius = 10.0;

            Struct_Ball ball2 = ball1; // 指定運算子'='會複製成員值

            // *----------
            // 在建立實例並初始化時，也可以使用成員名稱，不一定要按照成員名稱的定義順序來指定：
            struct Struct_Ball ball3 = { "red", 5.0 };                    // 顺序
            struct Struct_Ball ball3 = { color: "red", radius: 5.0 };     // C++ 風格亂序
            struct Struct_Ball ball3 = { .color = "red", .radius = 5.0 }; // C 風格亂序

            // !----------
            // 也可以在定義struct時，直接宣告struct實例，例如：
            struct Struct_Ball {
                string color;

                double radius;
            } ball1 = { "red", 5.0 }, ball2;
        }

        if (guide_cpp) // 結構陣列
        {
            // #include "_pch.hpp"

            struct Struct_Ball {
                double var_1;
                double var_2;
            };

            int main() {
                Struct_Ball Ball_1[] = {
                    {
                        .var_1 = 0.1,
                        .var_2 = 0.2,
                    },
                    {
                        .var_1 = 0.3,
                        .var_2 = 0.4,
                    },
                };

                system("pause");
                return 0;
            }
        }

        if (guide_cpp) // 位域
        {
            // #include "_pch.hpp"
            // #include <memory.h>

            struct A {
                int a : 5;
                int b : 3;
            };

            int main() {

                char str[ 100 ] = "0134324324afsadfsdlfjlsdjfl";

                struct A d;

                memcpy(&d, str, sizeof(A)); // 0 ASCII 0011 0000

                cout << d.a << endl; // -16 xxx1 0000
                cout << d.b << endl; // 1   001x xxxx

                system("pause");
                return 0;
            }
        }

        if (guide_cpp) // 在 struct 中，再宣告 struct
        {
            // 在 struct 中，也可以再宣告 struct ，例如：
            struct Student {
                char *name;
                int number;

                struct
                {
                    char *color;
                    double radius;
                } ball;
            }; // 可以看到，定義 struct 時，不一定要定義 struct 名稱，而可以直接在定義結構之後，直接宣告實例。

            struct Student student1;

            student1.name        = "caterpillar";
            student1.number      = 1;
            student1.ball.color  = "red";
            student1.ball.radius = 5.0;
        }

        if (guide_cpp) // 結構的指針
        {
            // 如果在函式的引數傳遞時，同樣也是將 struct 的成員值一個一個「複製」給函式上的參數，
            // 在程式的 foo() 呼叫中，將 ball 傳遞給 foo() 上的參數，並在 foo() 中改變radius，但由於是複製成員值，這並不影響 main() 當中的 ball 實例之成員值。

            // #include <stdio.h>
            typedef struct
            {
                string color;

                double radius;
            } Ball;

            // void foo(Ball *ball) { ball->radius = 100.0; } // 100.0 有修改 指向結構的指針
            // void foo(Ball ball) { ball.radius = 100.0; } // 5.0 無修改 僅被複製過來
            int main() {

                Ball ball = { "red", 5.0 };
                // foo(&ball); // 100.0 有修改 指向結構的指針
                foo(ball); // 5.0 無修改 僅被複製過來

                cout << "ball1 : " << ball.color << ", " << ball.radius << endl;

                system("pause");
                return 0;
            }
        }
    }
}

if (guide_cpp) // new(新增空間) & delete(刪除空間)
{
    // ! 尽量不要使用 malloc() 。 new 与 malloc() 相比， new 不只是分配了内存，它还创建了对象。

    if (guide_cpp) // new(新增空間)
    {
        // ! 尽量不要使用 malloc() 。 new 与 malloc() 相比， new 不只是分配了内存，它还创建了对象。

        double *new_ptr_1 = nullptr;
        new_ptr_1         = new double;
        // * equal
        double *new_ptr_2 = new double;

        char *new_ptr_3 = new char[ 20 ]; // ptr = new 空間(size = char * 20)

        // 如果自由存储区已被用完，可能无法成功分配内存。所以建议检查 new 运算符是否返回 nullptr 指针。
        double *new_ptr_1 = nullptr;
        if (!(new_ptr_1 = new double) ) {
            cout << "Error : out of memory." << endl;
            exit(1);
        }
    }

    if (guide_cpp) // delete(刪除空間)
    {
        delete new_ptr_1; // 刪除一般指標

        new_ptr_2 = new char[ 20 ];
        delete[] new_ptr_2; // 删除数组
    }
}

if (guide_cpp) // 指標與引用
{
    if (guide_cpp) // 指標
    {
        // !v| e.g. 指標 -----

        // #include "_pch.hpp"

        int main() {

            int var_1  = 1;
            int *ptr_1 = &var_1;

            cout << " var_1 : " << var_1 << endl;
            cout << "&var_1 : " << &var_1 << endl;

            cout << "\n ptr_1 : " << ptr_1 << endl;
            cout << "&ptr_1 : " << &ptr_1 << endl;
            cout << "*ptr_1 : " << *ptr_1 << endl;

            // ! res :
            //  var_1 : 1
            // &var_1 : 0x61fe4c
            //
            //  ptr_1 : 0x61fe4c
            // &ptr_1 : 0x61fe40
            // *ptr_1 : 1

            system("pause");
            return 0;
        }

        // !^| e.g. 指標 -----}
    }
}