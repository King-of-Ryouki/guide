// cpp_guide_special

// ******************************
// *
// * date    : 2018/02/09
// *
// * author  : 施冠年
// * mail    : Co6901251@gmail.com
// *
// * function:
// *
// * C++ 筆記 : 特殊情況篇
// *
// ******************************

int cpp_guide_special = 1;

if (cpp_guide_special) // ++i & i++ 區別
{
    // ! ++i 是左值，i++ 不是
    // ! i++ 會產生暫存變數，建議 for 迴圈中使用 ++i 而非 i++, 且更符合其意義
    for (int i = 0; i < 10; i++) {} // 不建議
    for (int i = 0; i < 10; ++i) {} // 建議

    // * 數值更新時間點與 ';' & 編譯器優化有關

    int var_1 = 0;

    ++var_1;                 // ! res : 1
    var_1++;                 // ! res : 2
    cout << ++var_1 << endl; // ! res : 3
    cout << var_1++ << endl; // ! res : 3 ==> 4

    // * 分隔線 -----

    // * ++var_1

    // mov     eax, [rbp+var_1] // * 變數位址
    // add     eax, 1           // * 暫存器++

    // mov     [rbp+var_1], eax // * 變數   = 暫存器++
    // mov     eax, [rbp+var_1] // * 暫存器 = 變數
    // mov     edx, eax

    // * var_1++

    // mov     eax, [rbp+var_1] // * 變數位址

    // lea     edx, [rax+1]     // * 暫存器 = 變數 + 1(變數本身未 + 1)
    // mov     [rbp+var_1], edx // * 變數   = 暫存器(變數 + 1)
    // mov     edx, eax
}

if (cpp_guide_special) // C++ 三目運算符的效率與正確寫法
{
    var_1 = var_1 ? 1 : 2; // * 一般寫法，但其實降低效率

    // mov     eax, [rbp+var_1]
    // test    eax, eax

    // mov     eax, 1 // * if
    // mov     eax, 2 // * else

    // mov     [rbp+var_1], eax
    // lea     rax, [rbp+var_1] // ! 多一條指令

    // * -----

    var_1 ? var_1 = 1 : var_1 = 2; // * 正確寫法(在 Java 中會錯誤)

    // mov     eax, [rbp+var_1]
    // test    eax, eax

    // mov     [rbp+var_1], 1 // * if
    // mov     [rbp+var_1], 2 // * else

    // mov     eax, [rbp+var_1]
}

if (cpp_guide_special) // switch 變數 { int var; }
{
    switch (x) {

        case 1:
            int var_1 = 0; // ! Error
            break;

        case 2: {
            int var_1 = 0; // ! Pass, 原因 : 作用域 {}
            break;
        }
    }
}

if (cpp_guide_special) // 陣列計算個數
{
    int arr_1[]    = { 0, 1, 2, 3, 4 };
    int arr_1_size = sizeof(arr_1) / sizeof(arr_1[ 0 ]); // ! res : 5
}

if (cpp_guide_special) // 大數
{
    // 大數解決方法 : 陣列, std::bitset, BigInt, BigInteger
}

if (cpp_guide_special) {
}

if (cpp_guide_special) {
}