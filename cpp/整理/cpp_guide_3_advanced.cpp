// cpp_guide_3_advanced

if // template // 模板
{
    // 模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。
    // 模板是创建泛型类或函数的蓝图或公式。库容器，比如迭代器和算法，都是泛型编程的例子，它们都使用了模板的概念。
    // 每个容器都有一个单一的定义，比如 向量，我们可以定义许多不同类型的向量，比如 vector <int> 或 vector <string>。
    // 可以使用模板来定义函数和类。

    else if // template 基礎
    {
        // !| -----
        template <typename T>
        inline T const &Max(T const &Var1, T const &Var2) { return Var1 < Var2 ? Var2 : Var1; }
        // 等價
        inline int const &Max(int const &Var1, int const &Var2) { return Var1 < Var2 ? Var2 : Var1; }
        inline double const &Max(double const &Var1, double const &Var2) { return Var1 < Var2 ? Var2 : Var1; }

        int main() {

            int i = 39, j = 20;          // typename T 會自動代換 int
            double f1 = 13.5, f2 = 20.7; // typename T 會自動代換 double
            Max(i, j);
            Max(f1, f2);

            system("pause");
            return 0;
        }
        // !| -----

        template <class T1, class T2>
        void Template1 {}

        template <typename T1, typename T2>
        void Template2 {}
        // 兩者皆可

        // 正如我们定义函数模板一样，我们也可以定义类模板。泛型类声明的一般形式如下所示：
        template <typename T>
        class Test {
            /* ... code ...  */
        }
        // 在这里，type 是占位符类型名称，可以在类被实例化的时候进行指定。您可以使用一个逗号分隔的列表来定义多个泛型数据类型。
        // 下面的实例定义了类 Stack<>，并实现了泛型方法来对元素进行入栈出栈操作：

        // 函数模板可以重载，只要它们的形参表不同即可。例如，下面两个模板可以同时存在：
        template <typename T1, typename T2>
        void print(T1 var1, T2 var2) {
            cout << var1 << ", " << var2 << endl;
        }
        template <typename T1>
        void print(T var1, T var2) { cout << var1 << ", " << var2 << endl; }

        else if // typename 和 class 的区别：
        {
            // class 关键字表明 T 是一个类型，后来为了避免 class 在这两个地方的使用可能给人带来混淆，所以引入了 typename

            // 在模板定义语法中关键字 class 与 typename 的作用完全一样。
            // typename 难道仅仅在模板定义中起作用吗？其实不是这样，typename 另外一个作用为：使用嵌套依赖类型(nested depended name)，如下所示：
            class MyArray {
            public:
                typedef int LengthType;
                /* ... */
            }

            template <class T>
            void MyMethod(T myarr) {
                typedef typename T::LengthType LengthType;
                LengthType length = myarr.GetLength;
            }
            // 这个时候 typename 的作用就是告诉 c++ 编译器，typename 后面的字符串为一个类型名称，而不是成员函数或者成员变量，
            // 这个时候如果前面没有 typename，编译器没有任何办法知道 T::LengthType 是一个类型还是一个成员名称(静态数据成员或者静态函数)，所以编译不能够通过。
        }
    }
}

if // class template // 類模板
{
    // 模板可以有层次，一个类模板可以作为基类，派生出派生模板类

    else if // class template | 特別
    {
        // 特殊類別的樣板：
        //
        // 當特殊化樣板之樣板參數列為空值，亦即不接受任何型態參數時，此特殊化樣板是一個被當成樣板的類別。
        // 當樣板參數列為空值時，則原型中出現的資料型態都必須指明為已宣告的資料型態。
        // 此時程序員的工作與設計一個傳統類別 (non-template class) 無異。差別僅在編譯器將此類別視為一個樣板，故使用時不需要區分兩者。
        // !| e.g. -----
        // Specialized class template
        template <>
        class Test<int> {};

        int main() {
            Test<int> var(2);
            return 0;
        }
        // !| -----
    }

    else if // class template | 多載
    {
        template <typename T1, typename T2>
        class Class1; // no.1

        template <typename T>
        class Class1<T, int>; // no.2

        Class1<int, int> a;    // no.2
        Class1<int, double> b; // no.1
    }

    else if // class template e.g.
    {
        else if // class 模板::class 外定義類模板
        {
            // !| -----
            // #include "pch.h"

            template <typename T>
            class Print {
            public:
                Print(T var1, T var2) { var1_ = var1, var2_ = var2; }
                T Var3() { var3_ = var1_ + var2_; }
                T Var4(); // class 外定義類模板

            private:
                T var1_, var2_, var3_, var4_;
            };

            template <typename T> // class 外定義類模板
            T Print<T>::Var4() {
                var4_ = var1_ * var2_;
            }

            int main() {
                Print<int> P1(1, 2);
                Print<float> P2(1.5, 2.5);

                system("pause");
                return 0;
            }
        }

        else if // class 模板::operator
        {
            // !| -----
            // #include "pch.h"

            template <typename T>
            class Sum {
            public:
                Sum(T var1, T var2) { var1_ = var1, var2_ = var2; }
                Sum operator+(Sum &OperSum) {
                    Sum TmpSum(var1_ + OperSum.var1_, var2_ + OperSum.var2_);
                    return TmpSum;
                }

            private:
                T var1_, var2_;
            };

            int main() {
                Sum<int> Var1(10, 20);
                Sum<int> Var2(20, 30);
                Sum<int> SumVar = Var1 + Var2;

                system("pause");
                return 0;
            }
        }

        else if // class 模板::继承
        {
            // 如果父类自定义了构造函数，记得子类要使用构造函数列表来初始化
            // 继承的时候，如果子类不是模板类，则必须指明当前的父类的类型，因为要分配内存空间
            // 继承的时候，如果子类  是模板类，要么指定父类的类型，要么用子类的泛型来指定父类
            // !| -----
            template <typename T>
            class Base {
            public:
                Base(T p) { b1 = p; }

            private:
                T b1;
            };

            // 如果子类不是模板类，需要指明父类的具体类型
            class Derive1 : public Base<int> {
            public:
                Derive1(int a, int b) : Base(b) { this->d1 = a; }

            private:
                int d1;
            };

            // 如果子类是模板类，可以用子类的泛型来表示父类
            template <typename T>
            class Derive2 : public Base<T> {
            public:
                Derive2(T a, T b) : Base<T>(b) { this->d2 = a; }

            private:
                T d2;
            };
            // !| -----
        }
    }
}

if // signal // 信号处理
{
    // http://www.runoob.com/cplusplus/cpp-signal-handling.html

    // 信号是由操作系统传给进程的中断，会提早终止一个程序。在 UNIX、LINUX、Mac OS X 或 Windows 系统上，可以通过按 Ctrl+C 产生中断。
    // 有些信号不能被程序捕获，但是下表所列信号可以在程序中捕获，并可以基于信号采取适当的动作。这些信号是定义在 C++ 头文件 <csignal> 中。

    // !v| 信号处理 -----
    // SIGABRT // 程序的异常终止，如调用 abort
    // SIGFPE  // 错误的算术运算，比如除以零或导致溢出的操作
    // SIGILL  // 检测非法指令
    // SIGINT  // 接收到交互注意信号
    // SIGSEGV // 非法访问内存
    // SIGTERM // 发送到程序的终止请求
    // !^| 信号处理 -----

    // C++ 信号处理库提供了 signal 函数，用来捕获突发事件
    void (*signal(int sig, void (*func)(int)))(int);
    // 这个函数接收两个参数：
    // 第一个参数是一个整数，代表了信号的编号；
    // 第二个参数是一个指向信号处理函数的指针。

    // e.g. 使用 signal() 函数捕获 SIGINT 信号。不管您想在程序中捕获什么信号，您都必须使用 signal 函数来注册信号，并将其与信号处理程序相关联

    // !v| e.g. raise() -----
    // #include "pch.h"

    // #include <csignal>
    // #include <unistd.h>

    void signalHandler(int signum) {
        cout << "Interrupt signal (" << signum << ") received.\n";
        exit(signum);
    }

    int main() {
        signal(SIGINT, signalHandler); // 注册信号 SIGINT 和信号处理程序

        int i = 0;
        while (++i) {
            cout << "Going to sleep...." << endl;
            if (i == 3) { raise(SIGINT); }
            sleep(1);
        }

        return 0;
    }
    // !^| e.g. raise() -----
}