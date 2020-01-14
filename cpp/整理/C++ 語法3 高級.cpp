// C++ 語法3 高級

if // template 模板
{
    template <class dataType>
    class Compare {
    private:
        dataType x, y;

    public:
        Compare(dataType a, dataType b) { x = a, y = b; }
        dataType GetMax() { return (x > y) ? x : y; } // dataType => <int> <float> <char>
    };

    int main() {
        Compare<int> num1(3, 7);
        cout << "Integer : " << num1.GetMax() << endl;

        Compare<float> num2(12.3, 23.4);
        cout << "Float   : " << num2.GetMax() << endl;

        Compare<char> num3('a', 'b');
        cout << "Char    : " << num3.GetMax() << endl;

        system("pause");
        return 0;
    }
}

if // 文件和流
{
    if // 檔案之輸入與輸出
    {
        // fopen()      // 開啟一個檔案
        // fclose()     // 關閉一個檔案
        // putc()       // 輸出一個字元到檔案
        // getc()       // 從某一個檔案讀取一個字元
        // fprintf()    // 輸出資料至某檔案
        // fscanf()     // 從某檔案讀取資料
        // feof()       // 測試是否到了檔案結束位置
        // ferror()     // 測試檔案操作是否正常
        // fseek()      // 設定準備讀取檔案資料的位置
        // rewind()     // 將準備讀取檔案資料位置，設定在檔案起始位置
        // remove()     // 檔案的刪除

        // fopen_s(FILE **pFile, const char *filename, const char *mode);
        FILE *Img;
        fopen_s(&Img, "img/sprite/sys/ad0.bmp", "rb");

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
        // fwrite()函數將array或是struct的內容寫入檔案中，第一個參數為array或是struct的指標，從這一個位址開始寫入，
        // 第二個參數為每一個元素被寫入的大小，第三個參數為寫入元素數量，第四個為指向FILE檔案指標。

        int main() {
            char buffer[] = { 'H', 'e', 'y' };

            FILE *pFile;
            pFile = fopen("write.txt", "w");
            if (pFile == NULL) {
                printf("open failure");
                return 1;
            } else {
                fwrite(buffer, 1, sizeof(buffer), pFile);
            }
            fclose(pFile);

            system("pause");
            return 0;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // fopen() 用於開啟檔案, 檔案在使用前是需先經過開啟動作的
        // 使用格式如下：
        FILE *fopen(char *filename, char *mode);

        // 各項資料的定義如下所示：
        // 1. *filename：檔案指標，指的是欲開啟的檔案名稱。
        // 2. *mode：檔案使用模式，指的是檔案被開啟之後，它的使用方式。
        // 下面是檔案開啟之後，一般常使用的方式：

        // r      以只讀方式打開文件，該文件必須存在。
        // r+     以讀/寫方式打開文件，該文件必須存在。
        // rb+    以讀/寫方式打開一個二進製文件，只允許讀/寫數據。
        // rt+    以讀/寫方式打開一個文本文件，允許讀和寫。

        // w      打開只寫文件，若文件存在則長度清為 0，即該文件內容消失，若不存在則創建該文件。
        //        開啟一個文字檔(text)，供程式將資料寫入此檔案內。如果磁碟內不包含這個檔案，則系統會自行建立這個檔案。如果磁碟內包含這個檔案，則此檔案內容會被蓋過而消失。
        // w+     打開可讀/寫文件，若文件存在則文件長度清為零，即該文件內容會消失。若文件不存在則建立該文件。
        // wb     以只寫方式打開或新建一個二進製文件，只允許寫數據。
        //        如果磁碟內不包含這個檔案，則系統會自行建立這個檔案。如果磁碟內包含這個檔案，此檔案內容會被蓋過而消失。
        // wb+    以讀/寫方式打開或建立一個二進製文件，允許讀和寫。
        // wt+    以讀/寫方式打開或建立一個文本文件，允許讀寫。

        // a      以附加的方式打開只寫文件(供程式將資料寫入此檔案的末端)。若文件不存在，則會建立該文件，如果文件存在，寫入的數據會被加到文件尾，即文件原先的內容會被保留（EOF 符保留）。
        // a+     以附加方式打開可讀/寫的文件。若文件不存在，則會建立該文件，如果文件存在，則寫入的數據會被加到文件尾後，即文件原先的內容會被保留（原來的 EOF 符不保留）。
        // ab     開啟一個二元檔(binary)，供程式將資料寫入此檔案末端，如果此檔案不存在，則系統會自行建立此檔案。
        // ab+    以讀/寫方式打開一個二進製文件，允許讀或在文件末追加數據。
        // at+    以讀/寫方式打開一個文本文件，允許讀或在文本末追加數據。

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // fclose() 用於關閉檔案, 如果fclose() 執行失敗，它的傳回值是非零值
        // 在C語言中關閉檔案主要有兩個目的：
        // 1. 檔案在關閉前會將檔案緩衝區資料寫入磁碟檔案內，否則檔案緩衝區資料會遺失。
        // 2. 一個Ｃ語言程式，在同一時間可開啟的檔案數量有限，一般是20個，如果你的程式很大，要開啟超過20個檔案時，你必須將暫時不用的檔案關閉。

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // fprintf() 主要目的是供你將資料，以格式化方式寫入某檔案內
        // 使用格式如下：
        fprintf(fp, "…….", ………);
        // 此函數控制列印區和列印和列印變數區的使用, 格式和printf() 使用格式相同.fprintf() 和printf() 兩者唯一的差別是，printf() 會將資料列印在螢幕上，而fprintf() 會將資料列印在某個檔案內。

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // fscanf() 主要的目的是讓我們從某個檔案讀取資料
        // 使用格式如下：
        fscanf(fp, "…….", ………);
        // fscanf() 函數和scanf() 函數兩者之間最大的差別在，scanf() 函數主要用於從鍵盤輸入讀取資料，fscanf() 函數則是從fp檔案指標所指的檔案讀取資料。

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // putc() 主要功能是將一個字元寫入某檔案內，
        // 格式如下
        int putc(int ch, FILE *fp);
        // 此函數如果執行成功，它的傳回值是ch字元值，如果執行失敗，它的傳回值是EOF。且上述格式中，ch代表所欲輸出的字元，fp則是檔案指標。

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // getc() 主要目的是某一個檔案中，讀取一個字元。
        // 使用格式如下：
        int getc(FILE * fp);
        // 當執行getc() 函數成功時，傳回值是所讀取的字元，如果所讀取的是檔案結束字元，則此值是EOF，在stdio.h內，此值是 - 1。
    }

    else if // 文件和流 開啟
    {
        // ofstream 該數據類型表示輸出文件流，用於創建文件並向文件寫入信息。
        // ifstream 該數據類型表示輸入文件流，用於從文件讀取信息。
        // fstream 該數據類型通常表示文件流，且同時具有 ofstream 和 ifstream 兩種功能，
        // 這意味著它可以創建文件，向文件寫入信息，從文件讀取信息。

        // 下面是 open() 函數的標準語法，open() 函數是 fstream、ifstream 和 ofstream 對象的一個成員。
        void open(const char *filename, ios::openmode mode);
        // 在這裡，open() 成員函數的第一參數指定要打開的文件的名稱和位置，第二個參數定義文件被打開的模式。

        // ios::in 打開文件用於讀取。
        // ios::out 打開文件用於寫入。
        // ios::ate 文件打開後定位到文件末尾。
        // ios::app 追加模式。所有寫入?m追加到文件末尾。
        // ios::trunc 如果該文件已經存在，其內容將在打開文件之前被截斷，即把文件長度設為 0。

        // 您可以把以上兩種或兩種以上的模式結合使用。例如，如果您想要以寫入模式打開文件，並希望截斷文件，以防文件已存在，那麼您可以使用下面的語法：
        ofstream outfile;
        outfile.open("file.dat", ios::out | ios::trunc);

        // 類似地，您如果想要打開一個文件用於讀寫，可以使用下面的語法：
        fstream afile;
        afile.open("file.dat", ios::out | ios::in);
    }

    else if // 文件和流 關閉
    {
        // 當 C++ 程序終止時，它會自動關閉刷新所有流，釋放所有分配的內存，並關閉所有打開的文件。但
        // 程序員應該養成一個好習慣，在程序終止前關閉所有打開的文件。

        // 下面是 close() 函數的標準語法，close() 函數是 fstream、ifstream 和 ofstream 對象的一個成員。
        void close();
    }

    else if // 文件和流 游標位置
    {
        // istream 和 ostream ?m提供了用於重新定位文件位置指針的成員函數。
        // 這些成員函數包括關於 istream 的 seekg("seek get") 和關於 ostream 的 seekp("seek put")。

        // seekg 和 seekp 的參數通常是一個長整型。第二個參數可以用於指定查找方向。
        // 查找方向可以是 ios::beg (默認的，從流的開頭開始定位)，也可以是 ios::cur (從流的當前位置開始定位)，也可以是 ios::end (從流的末尾開始定位)。
        // 文件位置指針是一個整數值，指定了從文件的??始位置到指針所在位置的字節數。下面是關於定位 "get" 文件位置指針的實例：

        fileObject.seekg(n);           // 定位到 fileObject 的第 n 個字節（假設是 ios::beg）
        fileObject.seekg(n, ios::cur); // 把文件的讀指針從 fileObject 當前位置向後移 n 個字節
        fileObject.seekg(n, ios::end); // 把文件的讀指針從 fileObject 末尾往回移 n 個字節
        fileObject.seekg(0, ios::end); // 定位到 fileObject 的末尾
    }
}

if // 異常處理
{
    if // 異常處理
    {
        // throw: 當問題出現時，程序會拋出一個異常。這是通過使用 throw 關鍵字來完成的。
        // catch: 在您想要處理問題的地方，通過異常處理程序捕獲異常。 catch 關鍵字用於捕獲異常。
        // try: try 塊中的代碼標識將被激活的特定異常。它後面通常跟著一個或多個 catch 塊。

        // 如果有一個塊拋出一個異常，捕獲異常的方法會使用 try 和 catch 關鍵字。
        // try 塊中放置可能拋出異常的代碼，try 塊中的代碼被稱為保護代碼。使用 try/catch 語句的語法如下所示：

        // 如果 try 塊在不同的情境下會拋出不同的異常，這個時候可以嘗試羅列多個 catch 語句，用於捕獲不同類型的異常。
        try {
        } // 保護代碼
        catch (ExceptionName e1) {
        } // catch 塊
        catch (ExceptionName e2) {
        } // catch 塊
        catch (ExceptionName e3) {
        } // catch 塊
    }

    else if // 拋出異常
    {
        // 您可以使用 throw 語句在代碼塊中的任何地方拋出異常。
        // throw 語句的操作數可以是任意的表達式，表達式的結果的類型決定了拋出的異??常的類型。
        // 以下是嘗試除以零時拋出異常的實例：
        double division(int a, int b) {
            if (b == 0) { throw "Division by zero condition!"; }
            return (a / b);
        }
    }

    else if // 捕獲異常
    {
        // catch 塊跟在 try 塊後面，用於捕獲異常。您可以指定想要捕捉的異常類型，
        // 這是由 catch 關鍵字後的括號內的異常聲明決定的。

        try {
        } // 保護代碼
        catch (ExceptionName e) {
        } // 處理 ExceptionName 異常的代碼

        // 上面的代碼會捕獲一個類型為 ExceptionName 的異常。如果您想讓 catch 塊能夠處理 try 塊拋出的任何類型的異常，
        // 則必須在異常聲明的括號內使用省略號 ...，如下所示：
        try {
        } // 保護代碼
        catch (...) {
        } // 能處理任何異常的代碼
    }

    else if // C++ 標準的異常
    {
        // C++ 提供了一系列標準的異常，定義在 <exception> 中，我們可以在程序中使用這些標準的異常。
        // 它們是以父子類層次結構組織??來的，如下所示：

        // std::exception 該異常是所有標準 C++ 異常的父類。
        {
            // std::bad_alloc 該異常可以通過 new 拋出。
            // std::bad_cast 該異常可以通過 dynamic_cast 拋出。
            // std::bad_typeid 該異常可以通過 typeid 拋出。
            // std::bad_exception 這在處理 C++ 程序中無法預期的異常時非常有用。

            // std::logic_error 理論上可以通過讀取代碼來檢測到的異常。
            {
                // std::domain_error 當使用了一個無效的數學域時，會拋出該異常。
                // std::invalid_argument 當使用了無效的參數時，會拋出該異常。
                // std::length_error 當創建了太長的 std::string 時，會拋出該異常。
                // std::out_of_range 該異常可以通過方法拋出，例如 std::vector 和 std::bitset<>::operator[]()。
            }

            // std::runtime_error 理論上不可以通過讀取代碼來檢測到的異常。
            {
                // std::overflow_error 當發生數學上溢時，會拋出該異常。
                // std::range_error 當嘗試存儲超出範圍的值時，會拋出該異常。
                // std::underflow_error 當發生數學下溢時，會拋出該異常。
            }
        }
    }

    else if // 補充
    {
        // const throw() 不是函數，這個東西叫異常規格說明，表示what 函數可以拋出異常的類型，
        // 類型說明放到() 裡，這裡面沒有類型，就是聲明這個函數不拋出異常，
        // 通常函數不寫後面的就表示函數可以拋出任何類型的異常。

        // 異常規格說明:
        // 1、異常規格說明的目的是為了讓函數使用?耵器D該函數可能拋出的異常有哪些。
        // 可以在函數的聲明中列出這個函數可能拋擲的所有異常類型。
        // 例如: void fun() throw(A，B，C，D);
        // 2、若無異常接口聲明，則此函數可以拋擲任何類型的異常。
    }
}

if // 動態內存
{
    if // 動態內存
    {
        // 棧：在函數內部聲明的所有變量都將佔用棧內存。
        // 堆：這是程序中未使用的內存，在程序運行時可用於動態分配內存。

        // 很多時候，您無法提前預知需要多少內存來存儲某個定義變量中的特定信息，所需內存的大小需要在運行時才能確定。
        // 在 C++ 中，您可以使用特殊的運算符為給定類型的變量在運行時分配堆內的內存，
        // 這會返回所分配的空間地址。這種運算符即 new 運算符。
        // 如果您不再需要動態分配的內存空間，可以使用 delete 運算符，刪除之前由 new 運算符分配的內存。

        new data - type;
        // 在這裡， data - type 可以是包括數組在內的任意內置的數據類型，也可以是包括類或結構在內的用戶自定義的任何數據類型。
        // 讓我們先來看下內置的數據類型。例如，我們可以定義一個指向 double 類型的指針，然後請求內存，
        // 該內存在執行時被分配。我們可以按照下面的語句使用 new 運算符來完成這點：
        double *pvalue = nullptr;    // 初始化為 null 的指針
        pvalue         = new double; // 為變量請求內存

        // malloc() 函數在 C 語言中就出現了，在 C++ 中仍然存在，但建議盡量不要使用 malloc() 函數。
        // new 與 malloc() 函數相比，其主要的優點是，new 不只是分配了內存，它還創建了對象。
        // 在任何時候，當您覺得某個已經動態分配內存的變量不再需要使用時，您可以使用 delete 操作符釋放它所佔用的內存，如下所示：
        delete pvalue; // 釋放 pvalue 所指向的內存

        // 如果自由存儲區已被用完，可能無法成功分配內存。所以建議檢查 new 運算符是否返回 NULL 指針，並採取以下適當的操作：
        double *pvalue = nullptr;
        if (!(pvalue = new double) ) {
            cout << "Error: out of memory." << endl;
            exit(1);
        }
    }

    else if // 數組的動態內存分配
    {
        // 假設我們要為一個字符數組（一個有 20 個字符的字符串）分配內存，
        // 我們可以使用上面實例中的語法來為數組動態地分配內存，如下所示：

        char *pvalue = nullptr;        // 初始化為 null 的指針
        pvalue       = new char[ 20 ]; // 為變量請求內存

        // 要刪除我們剛才創建的數組，語句如下：
        delete[] pvalue; // 刪除 pvalue 所指向的數組

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // 下面是 new 操作符的通用語法，可以為多維數組分配內存，如下所示：
        // 一維數組:
        int *array = new int[ m ];
        delete[] array; //釋放內存

        // 二維數組:
        int **array;
        // 假定數組第一維長度為 m， 第二維長度為 n
        array = new int *[ m ]; // 動態分配空間
        for (int i = 0; i < m; i++) { array[ i ] = new int[ n ]; }
        for (int i = 0; i < m; i++) { delete[] arrar[ i ]; }
        delete[] array;
    }
}

if // 命名空間
{
    if // 定義命名空間
    {
        // ! ----------
        // #include "pch.h"

        namespace first_space { // 第一個命名空間
            void func() { cout << "Inside first_space" << endl; }
        } // namespace first_space

        namespace second_space { // 第二個命名空間
            void func() { cout << "Inside second_space" << endl; }
        } // namespace second_space

        int main() {
            first_space::func();  // 調用第一個命名空間中的函數
            second_space::func(); // 調用第二個命名空間中的函數

            system("pause");
            return 0;
        }
    }

    else if // using 指令
    {
        // 您可以使用 using namespace 指令，這樣在使用命名空間時就可以不用在前面加上命名空間的名稱。
        // 這個指令會告訴編譯器，後續的代碼將使用指定的命名空間中的名稱。
        // ! ----------
        // #include "pch.h"

        namespace first_space { // 第一個命名空間
            void func() { cout << "Inside first_space" << endl; }
        } // namespace first_space

        namespace second_space { // 第二個命名空間
            void func() { cout << "Inside second_space" << endl; }
        } // namespace second_space

        using namespace first_space; // 調用第一個命名空間中的函數

        int main() {
            func();

            system("pause");
            return 0;
        }
    }

    else if // 不連續的命名空間
    {
        // 命名空間可以定義在幾個不同的部分中，因此命名空間是由幾個單獨定義的部分組成的。一個命名空間的各個組成部分可以分散在多個文件中。
        // 所以，如果命名空間中的某個組成部分需要請求定義在另一個文件中的名稱，則仍然需要聲明該名稱。
        // 下面的命名空間定義可以是定義一個新的命名空間，也可以是為已有的命名空間增加新的元素：

        namespace namespace_name {
            // ...
        }

        // 嵌套的命名空間
        // 命名空間可以嵌套，您可以在一個命名空間中定義另一個命名空間，如下所示：
        namespace namespace_name1 {
            // ...
            namespace namespace_name2 {
                // ...
            } // namespace namespace_name2
        }     // namespace namespace_name1

        // 您可以通過使用 :: 運算符來訪問嵌套的命名空間中的成員：
        // 訪問 namespace:name1 中的成員
        using namespace namespace_name1;

        // 訪問 namespace_name2 中的成員
        using namespace namespace_name1::namespace_name2;
        // 在上面的語句中，如果使用的是 namespace_name1，那麼在該範圍內 namespace_name2 中的元素也是可用的，如下所示：

        namespace first_space { // 第一個命名空間
            void func() { cout << "Inside first_space" << endl; }
            namespace second_space { // 第二個命名空間
                void func() { cout << "Inside second_space" << endl; }
            } // namespace second_space
        }     // namespace first_space

        using namespace first_space::second_space;

        int main() {
            func(); // 調用第二個命名空間中的函數

            system("pause");
            return 0;
        }
    }
}