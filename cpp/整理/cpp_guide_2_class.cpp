// cpp_guide_2_class // 物件導向

if // class | 類
{
    if // class | 基礎
    {
        // 编译器会自动声明 4 个默认函数：
        // 构造函数、拷贝构造函数、析构函数、赋值函数
        //
        // 如果不想使用自动生成的函数，就应该明确拒绝，这些生成的函数都是 public 且 inline
        //
        // 构造函数对数据成员进行初始化，使用未初始化值可能导致无法预知的错误，所以，确保每一个构造函数都将每一个成员初始化
        //
        // 构造函数不能有返回值
        // 如果有返回值
        // 要么编译器必须知道怎么处理返回值
        // 要么就客户程序员显式调用构造函数和析构函数
        // 这样，还有安全性么？
        //
        // 构造函数不能为虚函数
        // 虚函数调用的机制，是知道接口而不知道其准确对象类型的函数，但是创建一个对象，必须知道对象的准确类型；
        // 当一个构造函数被调用时，它做的首要事情之一就是初始化它的 VPTR 来指向 VTABLE.
    }

    else if // class | 訪問權限 | public (公有) 、 private (私有) 、 protected (保護)
    {
        // 一個類中可以有多個 public (公有) 、 private (私有) 、 protected (保護)
        // public 在外部是可訪問的，可以不使用任何成員函數來設置和獲取公有變量的值
        // private 和 protected 不能使用直接成員訪問運算符 (.) 來直接訪問
        // !| e.g. -----
        // #include "pch.h"

        class Test {
        public: // 公有 // 子類可讀, class 外可讀
            int var_public_ = 1;

        protected: // 保護 // 子類可讀
            int var_protected_ = 2;

        private: // 私有 // 子類不可讀
            int var_private_ = 3;
        } Test;

        int main() {
            Test.var_public_ = 5;
            // Test.var_private_ = 5; // error
            // Test.var_private_ = 5; // error

            system("pause");
            return 0;
        }
    }

    else if // class | 構造函數 (constructor)
    {
        // 构造函数对数据成员进行初始化，使用未初始化值可能导致无法预知的错误，
        // 所以，确保每一个构造函数都将每一个成员初始化。

        // 在每次創建類的新對象時執行
        // 構造函數與 class 的名稱相同
        // !| 構造函數 -----
        class Test {
            Test() {}
        };

        // 不會返回任何類型, void
        // 可用於為某些成員變量設置初始值
        // !| 初始化 -----
        Line(double var) : length_(var) {}
        Line(double var) { length_ = var; } // 等價

        // !| e.g. -----
        // #include "pch.h"

        class Test {
        public:
            Test() { cout << "1" << endl; } // 構造函數 進入時執行
        };

        int main() {
            Test Test; // print "1"

            system("pause");
            return 0;
        }
    }

    else if // class | 構造函數 (constructor) | 初始化列表 (member initialization list)
    {
        // 有四种情况下应该使用初始化表达式来初始化成员：
        //
        // 1、初始化const成员
        // 2、初始化引用成员
        // 3、调用  基类的构造函数，而它拥有一组参数时
        // 4、调用成员类的构造函数，而它拥有一组参数时
        //
        // 其实冒号后的内容是初始化成员列表，一般有三种情况：
        //
        // 1、对含有对象成员的对象进行初始化
        // 类 line 有两个私有对象成员 startpoint, endpoint 的构造函数写成：
        // line(int sx, int sy, int ex, int ey) : startpoint(sx, sy), endpoint(ex, ey) {} // 初始化时按照类定义中对象成员的顺序分别调用各自对象的构造函数，再执行自己的构造函数
        //
        // 2、初始化成员变量
        // 类rectangle有两个数据成员length、width, 其构造函数写成：
        // rectangle() : length(1), width(2) {}
        // rectangle(int x, int y) : length(x), width(y) {}
        //
        // 3、对父类进行初始化
        // CDlgCalcDlg 的父类是 MFC 类 CDialog , 其构造函数写为：
        // CDlgCalcDlg(CWnd *pParent) : CDialog(CDlgCalcDlg::IDD, pParent) {}
        // 其中 IDD 是一个枚举元素，标志对话框模板的 ID
        // 使用初始化成员列表对对象进行初始化，有时是必须的，有时是出于提高效率的考虑
        //
        // 在初始化的时候调用的是拷贝构造函数
        // !v| e.g. 初始化列表 -----
        // #include "pch.h"

        class Init {
        public:
            Init(int &r_var2, int var3) : var4_(var1_), var1_(1), r_var2_(r_var2), var3_(var3) {} // 初始化列表的初始化以宣告順序為主，順序為： 1234 而非 4123
            void Print() {
                cout
                    << "var1_ : " << var1_ << "\n"
                    << "var2_ : " << r_var2_ << "\n"
                    << "var3_ : " << var3_ << "\n"
                    << "var4_ : " << var4_ << endl;
            }

        private:
            // 初始化列表的初始化以宣告順序為主
            int var1_;       // 僅申請空間
            int &r_var2_;    // 僅申請空間 // 不用初始化列表的話, error
            const int var3_; // 僅申請空間 // 不用初始化列表的話, error
            int var4_;       // 宣告順序測試
        };

        int main() {
            int var2 = 2;
            Init Init1(var2, 3);
            Init1.Print();

            system("pause");
            return 0;
        }
        // !^| e.g. 初始化列表 -----

        // !v| e.g. 初始化列表_繼承 -----
        // #include "pch.h"

        class Base {
        public:
            Base(int var1, int var2) { var1_ = var1; }

        protected:
            int var1_;
        };

        class Derived : public Base {
        public:
            Derived(int var1, int var2) : Base(var1, 0), var2_(var2) {}
            void Print() { cout << var2_ + Base::var1_ << endl; }

        private:
            int var2_;
        };

        int main() {
            Derived Test(2, 3);
            Test.Print();

            system("pause");
            return 0;
        }
        // !^| e.g. 初始化列表_繼承 -----
    }

    else if // class | 拷貝函數
    {
        // 拷貝函數 == 拷貝構造函數

        // 必須定義拷貝函數的情況：
        // 只包含 class 類型成員或內置類型（但不是指針類型）成員的類，無須顯式地定義拷貝構造函數也可以拷貝
        // 有的 class 有一個數據成員是指針，或有成員表示在構造函數中分配的其他資源，這兩種情況下必須定義拷貝構造函數

        // 什麼情況使用拷貝構造函數：
        // 類的對象需要拷貝時，拷貝構造函數將會被調用。以下情況會調用拷貝構造函數：
        // 1. 一個對象以值傳遞的方式傳入函數體
        // 2. 一個對象以值傳遞的方式從函數返回
        // 3. 一個對象需要通過另外一個對象進行初始化。
        //
        // 拷貝構造函數 通常會加 const & 固定位址
        // e.g.
        Test(const Test &TestCopy) {}

        // 拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。拷贝构造函数通常用于：
        //
        // 通过使用另一个同类型的对象来初始化新创建的对象。
        // 复制对象把它作为参数传递给函数。
        // 复制对象，并从函数返回这个对象。

        // !| e.g. 拷貝構造函數 -----
        // #include "pch.h"

        class CopyConstructor {
        public:
            CopyConstructor(int var) { // 初始化用的構造函數
                cout << "constructor" << endl;
                copy_var_  = new int;
                *copy_var_ = var;
            }
            CopyConstructor(const CopyConstructor &CopyConstructor_Tmp) { // 多態 // 拷貝構造函數，通常會加 const & 固定位址
                cout << "copy constructor" << endl;
                copy_var_  = new int;
                *copy_var_ = *CopyConstructor_Tmp.copy_var_;
            }
            ~CopyConstructor() { delete copy_var_; }
            int GetCopyConstructor() { return *copy_var_; }

        private:
            int *copy_var_;
        } CopyConstructor_1(10), CopyConstructor_2(20), CopyConstructor_3(30);

        void PrintCopyConstructor(CopyConstructor CopyConstructor_Tmp) { cout << "CopyConstructor's var : " << CopyConstructor_Tmp.GetCopyConstructor() << endl; }

        int main() {
            PrintCopyConstructor(CopyConstructor_1);

            system("pause");
            return 0;
        }
    }

    else if // class | 析構函數
    {
        // 在每次刪除所創建的對象時執行
        // 析構函數與 class 的名稱相同
        // 前面加了 ~ 作為前綴
        // !| e.g. -----
        class Test {
            ~Test() {}
        };
        // 它不會返回任何值，也不能帶有任何參數
        // 析構函數有助於在跳出程序（比如關閉文件、釋放內存等）前釋放資源
        ~Test() { delete *ptr; } // 釋放內存

        // !| 析構函數 -----
        // #include "pch.h"

        class Base {
        public:
            virtual ~Base() { cout << "Base" << endl; } // 不加 virtual 會直接 ~Base()
        };
        class Derived1 : public Base {
        public:
            ~Derived1() { cout << "Derived1" << endl; }
        };
        class Derived2 : public Derived1 {
        public:
            ~Derived2() { cout << "Derived2" << endl; }
        };

        int main() {
            Derived1 *Derived1 = new Derived2; // 宣告完類名之後的 new 只是開空間
            delete Derived1;
            // Base *Base = new Derived2();
            // delete Base;

            system("pause");
            return 0;
        };
    }

    else if // class | 函數
    {
        // 成員函數可以在 class 內部定義
        // 或使用範圍解析運算符 :: 在 class 外部定義
        // 在類定義中定義的成員函數把函數聲明為內聯 (inilne)
        class Test {
        public:
            int FuncInClass() { return 0; }
            int FuncOutClass();
        };
        int Test::FuncOutClass() { return 0; } // class | name::Func() {}

        // 如果想把一個函數定義為內聯函數，則需要在函數名前面放置關鍵字 inline ，在調用函數之前需要對函數進行定義
        // 如果已定義的函數多於一行，編譯器會忽略 inline
        // 在類定義中的定義的函數是內聯函數，即使沒有使用 inline
        //
        // 在內聯函數內不允許使用循環語句和開關語句
        // 內聯函數的定義必須出現在內聯函數第一次調用之前
        // 類結構中所在的類說明內部定義的函數是內聯函數
        // 盡量小於 10 行

        inline int Max(int x, int y) { return (x > y) ? x : y; }
        cout << "Max (20, 10): " << Max(20, 10) << endl;
        // 等價
        cout << "Max (20, 10): " << (20 > 10) ? 20 : 10 << endl;
    }

    else if // class | static 靜態成員 (變數 / 函數)
    {
        // static function // 靜態成員函數
        // static variable // 靜態成員變數

        // 如果把函數成員聲明為靜態的，就可以把函數與類的任何特定對象獨立開來
        //
        // static variable 在 class 中僅能聲明，不能定義，實際上是給 static variable 分配內存
        // 如果不加定義就會報錯，初始化是賦一個初始值，而定義是分配內存
        //
        // static function 沒有 this 指針，只能訪問 static variable 、 static function 和 class 外部的其他函數
        //
        // static function 即使在類對象不存在的情況下也能被調用， static function 只要使用類名加範圍解析運算符::就可以訪問
        // !| e.g. -----
        // #include "pch.h"

        class Test {
        public:
            static void Test_1() { cout << static_int_var_ << endl; }
            // static void Test_2() { cout << var_ << endl; } // error

        public:
            int var_ = 2;
            static int static_int_var_; // static 在 class 中僅能聲明，不能定義
        };

        int Test::static_int_var_ = 5; // static 只能在 class 外定義

        int main() {
            Test Test;
            Test.Test_1();

            system("pause");
            return 0;
        }
    }

    else if // class | friend 友元函數
    {
        // 用途：
        // 主要用于 operator
        // 数据共享时，减少系统开销，提高效率
        // 除上不建議使用，因為破壞了 class 的封裝性

        // 友元函數沒有 this 指針
        // 友元可以是一個 Function ，該函數被稱為友元函數
        // 友元也可以是一個 class ，該類被稱為友元類，在這種情況下，整個類及其所有成員是友元
        // 如果要聲明函數為一個 class 的友元，需要在 class 定義中該函數原型前使用關鍵字 friend
        //
        // class 的友元函數是定義在 class 外，但可訪問 class 的 private 和 protected
        // 儘管 class 的定義中出現過，但是友元函數並不是成員函數
        //
        // 參數要有三種情況：
        // 要訪問非 static 成員時，需要對象做參數
        // 要訪問 static 成員或全局變量時，則不需要對象做參數
        // 如果做參數的對象是全局對象，則不需要對象做參數可直接調用友元函數
        // !| -----
        // #include "pch.h"

        class Box {
        private:
            double length_;

        public:
            void SetLength(double length) { length_ = length; }
            friend void PrintLength(Box Box1);
        } Box1;

        void PrintLength(Box Box1) { cout << "length_ of Box1 : " << Box1.length_ << endl; } // PrintLength(Box Box1) 不是任何類的成員函數

        int main() {
            Box1.SetLength(10.0); // 使用成員函數設置長度
            PrintLength(Box1);    // 使用友元函數輸出長度

            system("pause");
            return 0;
        }
    }

    else if // class | 指向類的指標
    {
        // !| -----
        // #include "pch.h"

        class BoxVolume {
        public:
            BoxVolume(double length, double breadth, double height) {
                length_  = length;
                breadth_ = breadth;
                height_  = height;
            }
            double Volume() { return length_ * breadth_ * height_; } // 體積

        private:
            double length_;  // 長
            double breadth_; // 寬
            double height_;  // 高
        };

        int main() {
            BoxVolume BoxVolume1(3.0, 3.0, 3.0);
            BoxVolume *p_BoxVolume2 = &BoxVolume1;
            cout << "p_BoxVolume2's Volume : " << p_BoxVolume2->Volume() << endl;

            system("pause");
            return 0;
        }
    }
}

if // class 繼承
{
    if // class 繼承 基礎
    {
        // 當創建一個類時，不需要重新編寫新的數據成員和成員函數，只需指定新建的類繼承了一個已有的類的成員即可
        // 這個已有的類稱為基類，新建的類稱為派生類，繼承代表了關係
        // 例如：狗是動物
        // !| e.g. -----
        class animal {
        public:
            animal() {}
        };
        class Dog : public animal {
        public:
            Dog() {}
        };

        // 訪問控制和繼承
        //
        //               公有           保護       私人
        // 訪問        public     protected    private
        // in class       yes           yes        yes
        // friend         yes           yes        yes
        // 派生           yes           yes         no
        // out class      yes            no         no

        // 繼承層級
        // public 繼承：
        // public, protected, private ==> public, protected, private
        //
        // protected 繼承：
        // public, protected, private ==> protected, protected, private
        //
        // private 繼承：
        // public, protected, private ==> private, private, private

        // 一個派生類繼承了所有的基類方法，但下列情況除外：
        // 基類的構造函數、析構函數、拷貝構造函數
        // 基類的重載運算符
        // 基類的友元函數
    }

    if // class 繼承 | 派生 保護 可訪問
    {
        // 與私有十分相似, 但保護成員在派生類(子類)中是可訪問的
        // 當一個類派生自基類，該基類可以被繼承為 public、protected 或 private 幾種類型。
        // 繼承類型是通過訪問修飾符 access-specifier 來指定的。

        // 幾乎不使用 protected 或 private 繼承，通常使用 public 繼承。當使用不同類型的繼承時，遵循以下幾個規則：
        // 公有繼承（public）：當一個類派生自公有基類時，基類的公有成員也是派生類的公有成員，
        // 基類的保護成員也是派生類的保護成員，基類的私有成員不能直接被派生類訪問，
        // 但是可以通過調用基類的公有和保護成員來訪問。
        // 保護繼承（protected）: 當一個類派生自保護基類時，基類的公有和保護成員將成為派生類的保護成員。
        // 私有繼承（private）  : 當一個類派生自私有基類時，基類的公有和保護成員將成為派生類的私有成員。

        class Box {
        protected:
            double length_;
        };

        class SmallBox : Box { // SmallBox 是派生類、子類, Box 是基類
        public:
            void SetLength(double length) { length_ = length; }
            double GetLength(void) { return length_; }
        } Box1;

        struct B : A {
            char b;
        }; // 默認 public: // struct B : public A 表示
    }

    if // class 繼承 | 多繼承
    {
        // 多繼承即一個子類可以有多個父類，它繼承了多個父類的特性
        // ! e.g. 多繼承 -----
        // #include "pch.h"

        class Shape {
        public:
            void SetLength(int length) { length_ = length; }
            void SetWidth(int width) { width_ = width; }

        protected:
            int length_, width_;
        };

        class PaintCost {
        public:
            int GetCost(int area) { return area * 10; }
        };

        class Rectangle : public Shape, public PaintCost {
        public:
            int GetArea() { return length_ * width_; }
        } Rect;

        int main() {
            int length, width;

            cout << "Input Length : ";
            cin >> length;
            cout << "Input Width  : ";
            cin >> width;
            cout << endl;

            Rect.SetLength(length);
            Rect.SetWidth(width);
            int area = Rect.GetArea();

            cout << "area     : " << Rect.GetArea() << endl;
            cout << "how much : " << Rect.GetCost(area) << endl;

            system("pause");
            return 0;
        }
    }

    if // class 繼承 | 虚继承
    {
        // 虚继承是一种机制，类通过虚继承指出它希望共享虚基类的状态。

        // 最典型的应用就是 iostream 继承于 istream 和 ostream
        // 而 istream 和 ostream 虚继承于 ios
        class istream : virtual public ios {};
        class ostream : virtual public ios {};
        class iostream : public istream, public ostream {};

        // 注意
        // （1）支持到基类的常规转换。也就是说即使基类是虚基类，也照样可以通过基类指针或引用来操纵派生类的对象。
        // （2）虚继承只是解决了菱形继承中派生类多个基类内存拷贝的问题，并没有解决多重继承的二义性问题。
        // （3）通常每个类只会初始化自己的直接基类，如果不按虚继承处理，那么在菱形继承中会出现基类被初始两次的情况，
        //  在上例中也就是A→B→A→C→D。为了解决这个重复初始化的问题，虚继承对初始化进行了特殊处理。
        // 在虚继承中，由最底层派生类的构造函数初始化虚基类。

        else if // 虚继承 error
        {
            // !| 虚继承 error  -----
            // #include "pch.h"

            class A {
            public:
                A() : a(1){};

                void printA() { cout << a << endl; }

                int a;
            };

            class B : public A {};
            class C : public A {};
            class D : public B, public C {};

            int main() {
                D DD;
                cout << sizeof(DD); // 8, ==> (int a) * 2

                DD.a = 10;   //error, request for member 'a' is ambiguous
                DD.printA(); //error, request for member 'printA' is ambiguous

                DD.B::a = 10;            // pass, 但不建議
                cout << DD.B::a << endl; // pass, 但不建議

                system("pause");
                return 0;
            }
        }

        // 对给定的虚基类，无论该类在派生层次中作为虚基类出现多少次，只继承一个共享的基类子对象，共享基类子对象称为虚基类。
        // 虚基类用 virtual 声明继承关系就行了。这样一来，D 就只有 A 的一份拷贝。

        else if // 虚继承 pass
        {
            // #include "pch.h"

            class A {
            public:
                A() : a(1){};
                void printA() { cout << a << endl; }
                int a;
            };

            class B : virtual public A {};
            class C : virtual public A {};
            class D : public B, public C {};

            int main() {
                D DD;
                cout << sizeof(DD) << endl; // 24 // 原文：输出 DD 的大小是12（包含了 2个4字节的 D 类虚基指针和 1个4 字节的 int 型整数）

                DD.a = 10;
                DD.printA();

                system("pause");
                return 0;
            }
        }
    }

    if // class 繼承 | 多繼承(環狀繼承), A->D, B->D, C->(A，B) 例如：
    {
        class D {};
        class A : public D {};
        class B : public D {};
        class C : public A, public B {};

        // 這個繼承會使 D 創建兩個對象,要解決上面問題就要用虛擬繼承格式
        // 格式：class 類名: virtual 繼承方式 父類名

        class D {};
        // 虛繼承（在創建對象的時候會創建一個虛表）在創建父類對象的時候
        // class sizeof = 4, virtual sizeof = 8
        class A : virtual public D {}; // sizeof = 4 + 8 + 4 = 16
        class B : virtual public D {};
        class C : public A, public B {}; // sizeof = 4 + 4: + 16 + 16 = 40
    }

    if // class 繼承 | 基類與虚继承的初始化順序
    {
        // 繼承的初始化順序
        // 基類優先
        // 若有虚继承，則虚继承最優先初始化
        // 虚继承 > 基類
        // !| e.g. 基類 -----
        // #include "pch.h"

        class A {};
        class B : public A {};
        class C : public B {};

        int main() {
            C CC; // 初始化順序，基類優先： A ==> B ==> C

            system("pause");
            return 0;
        }
        // !| e.g. 虚继承 -----
        // #include "pch.h"

        class A {};
        class B : public A {};
        class C {};
        class D : public B, virtual C {};

        int main() {
            D DD; // 初始化順序，虚继承 > 基類： virtual C ==> A ==> B ==> D

            system("pause");
            return 0;
        }
    }

    if // class 繼承 | Abstract 抽象
    {
        // Abstract class == 抽象 class

        // 设计策略
        // 面向对象的系统可能会使用一个抽象基类为所有的外部应用程序提供一个适当的、通用的、标准化的接口。
        // 然后，派生类通过继承抽象基类，就把所有类似的操作都继承下来。
        // 外部应用程序提供的功能（即公有函数）在抽象基类中是以纯虚函数的形式存在的。这些纯虚函数在相应的派生类中被实现。
        // 这个架构也使得新的应用程序可以很容易地被添加到系统中，即使是在系统被定义之后依然可以如此。

        else if // 接口 (抽像類)
        {

            // 接口描述了類的行為和功能，而不需要完成類的特定實現。
            // C++ 接口是使用抽像類來實現的，抽像類與數據抽象互不混淆，數據抽像是一個把實現細節與相關的數據分離開的概念。
            // 如果類中至少有一個函數被聲明為純虛函數，則這個類就是抽像類。純虛函數是通過在聲明中使用 " = 0 " 來指定的

            class Box // 抽像類
            {
            public:
                virtual double getVolume() = 0; // 純虛函數

            private:
                double length_;  // 長度
                double breadth_; // 寬度
                double height_;  // 高度
            };
            // 設計抽像類 (通常稱為 ABC) 的目的，是為了給其他類提供一個可以繼承的適當的基類。
            // 抽像類不能被用於實例化對象，它只能作為接口使用。如果試圖實例化一個抽像類的對象，會導致編譯錯誤。
            // 因此，如果一個 ABC 的子類需要被實例化，則必須實現每個虛函數，這也意味著 C++ 支持使用 ABC 聲明接口。
            // 如果沒有在派生類中重載純虛函數，就嘗試實例化該類的對象，會導致編譯錯誤。
            // 可用於實例化對象的類被稱為具體類。
        }

        else if // 數據抽象
        {
            // 好处：
            // 类的内部受到保护

            // 只向外界提供关键信息，并隐藏其后台的实现细节
            // 由公共成员来定义, 私有部分实现细节。

            // 接口和实现：
            // public : 接口
            // private: 實現

            // 如果只在类的私有部分定义数据成员，编写该类的作者就可以随意更改数据。
            // 如果实现发生改变，则只需要检查类的代码，看看这个改变会导致哪些影响。
            // 如果数据是公有的，则任何直接访问旧表示形式的数据成员的函数都可能受到影响。

            // 如果只在類的私有部分定義數據成員，編寫該類的作就可以隨意更改數據。
            // 如果實現發生改變，則只需要檢查類的代碼，看看這個改變會導致哪些影響。
            // 如果數據是公有的，則任何直接訪問舊表示形式的數據成員的函數可能受到影響。

            // 數據抽像有兩個重要的優勢：
            // 類的內部受到保護，不會因無意的用戶級錯誤導致對象狀態受損。
            // 類實現可能隨著時間的推移而發生變化，以便應對不斷變化的需求，或應對那些要求不改變用戶級代碼的錯誤報告。
            // !| -----
            // #include "pch.h"

            class Adder {
            public:
                Adder() {} // 構造函數

                void AddNum(int num) { total_ += num; } // 對外的接口
                int Total() { return total_; };         // 對外的接口

            private:
                int total_ = 0; // 對外隱藏的數據
            };

            int main() {
                Adder Add;
                Add.AddNum(10);
                Add.AddNum(20);
                Add.AddNum(30);

                cout << "Total : " << Add.Total() << endl;

                system("pause");
                return 0;
            }
        }

        else if // 數據封裝
        {
            // 封裝是面向對象編程中的把數據和操作數據的函數綁定在一的一個概念，這樣能避免受到外界的干擾和誤用，
            // 從而確保了安全。數據封裝引申出了另一個重要的 OOP 概念，即數據隱藏。
            // 數據封裝是一種把數據和操作數據的函數捆綁在一的機制，數據抽像是一種僅向用戶暴露接口而把具體的實現細節隱藏來的機制。
        }
    }

    else if // class 繼承 | 向上轉型
    {
        // * 向上轉型(upcasting) 會丟失子類特有的方法
        // * java 中若要在子类调用父类的方法，需使用关键字 super
        // * C++ 會先調用父類方法，要讀子類需用純虛函數

        // !v| e.g. 向上轉型 -----

        // #include "../../_pch.hpp"

        class Class1 {
        public:
            void Test1() { cout << "Class1 Test1" << endl; }
            virtual void Test2() = 0;
            virtual void Test3() { cout << "Class1 Test3" << endl; }
        };

        class Class2 : public Class1 {
        public:
            void Test1() { cout << "Class2 Test1" << endl; }
            void Test2() { cout << "Class2 Test2" << endl; }
            void Test3() { cout << "Class2 Test3" << endl; }
            void Test4() { cout << "Class2 Test4" << endl; }
        };

        int main() {

            Class1 *Class1 = new Class2;

            Class1->Test1(); // ! res : Class1 Test1
            Class1->Test2(); // ! res : Class2 Test2
            Class1->Test3(); // ! res : Class2 Test3
            // Class1->Test4(); // ! err

            system("pause");
            return 0;
        }

        // !^| e.g. 向上轉型 -----

        // 向下轉型
        // Animal a = new Bird(); // upcasting
        // Bird b;
        // b = (Bird)a; // downcasting, compile correct

        // static_cast
        // 用法：static_cast < type-id > ( exdivssion )
        // 運算符把exdivssion轉換為type-id類型，但沒有保證轉換的安全性。

        // dynamic_cast
        // 用法：dynamic_cast < type-id > ( exdivssion )
        // 比起static_cast有比較安全的轉型機制
    }
}

if // class | 繼承 & 組合
{
    if // 繼承
    {
        // 若在逻辑上B 是一种A （is a kind of），则允许B 继承A 的功能，它们之间就是Is-A 关系。
        // 如男人（Man）是人（Human）的一种，女人（Woman）是人的一种。那么类Man 可以从类Human 派生，类Woman也可以从类Human 派生。

        class Human {};
        class Man : public Human {};
        class Woman : public Human {};
    }

    if // 組合
    {
        // 若在逻辑上A 是B 的“一部分”（a part of），则不允许B 继承A 的功能，而是要用A和其它东西组合出B，它们之间就是“Has-A关系”。
        // 例如眼（Eye）、鼻（Nose）、口（Mouth）、耳（Ear）是头（Head）的一部分，
        // 所以类Head 应该由类Eye、Nose、Mouth、Ear 组合而成，不是派生而成。

        class Eye {
        public:
            void Look() {}
        };

        class Nose {
        public:
            void Smell() {}
        };

        class Mouth {
        public:
            void Eat() {}
        };

        class Ear {
        public:
            void Listen() {}
        };

        // ! 正确的设计，冗长的程序
        class Head {
        public:
            void Look() { Eye_.Look(); }
            void Smell() { Nose_.Smell(); }
            void Eat() { Mouth_.Eat(); }
            void Listen() { Ear_.Listen(); }

        private:
            Eye Eye_;
            Nose Nose_;
            Mouth Mouth_;
            Ear Ear_;
        };

        // ! 错误的设计
        class Head : public Eye, public Nose, public Mouth, public Ear {};

        int main() {
            Head Head;
            Head.Look();

            system("pause");
            return 0;
        }
    }

    if // ! e.g. 圆不是椭圆 -----
    {
        class OvalShape {
        public:
            void setSize(float x);
        };

        class Ellipse : public OvalShape { // 椭圆
        public:
            void setSize(float x, float y);
        };

        class Circle : public OvalShape { // 圆
        };
    }
}

if // 雙冒號(::)、點(.)、箭頭(->) == (*XXX).
{
    // 雙冒號(::)只用在 class 成員函式
    // !| -----
    // #include "pch.h"

    class Test {
    public:
        int var = 5;
        int Add(int a);
    };
    int Test::Add(int a) { return a + var; } // 雙冒號可對目前 class 表示內部變數

    int main() {
        Test Test;
        cout << Test.Add(5) << endl;

        system("pause");
        return 0;
    }

    // *| XXX. (*XXX). XXX-> -----
    class Test {
        int var;
    };
    Test Test;
    Test.var = 1;

    Test *p_Test;
    (*p_Test).var = 1;
    p_Test->var   = 1; // 等價
}

if // this 指針
{
    if // this 指針 基礎
    {
        // this 是 C++ 中的一个关键字，也是一个 const 指针，它指向当前对象，通过它可以访问当前对象的所有成员。
        // 所谓当前对象，是指正在使用的对象。例如对于 stu.show(); stu 就是当前对象，this 就指向 stu。
        // this 只能用在类的内部，通过 this 可以访问类的所有成员，包括 private、protected、public.

        // 當參數與對象數據成員變量名相同時必須顯式調用this指針，否則會出現參數自賦值的情況，且數據成員並未被賦值

        // this 為指向 class 中的對象的指針，因類中沒有類名（例：Test Test_1;）
        // 因此使用 this 代替：
        // *this.obj_1 ==> this->obj_1 // (*.) == (->)
        // 注意， this 是一个指针，要用 this-> ( == *this.) 来访问成员变量或成员函数。

        // this 是参数，表示对象首地址，调用成员函数时自动获取当前对象的地址，函数调用结束后， this 销毁。
        // this 是 const 指针，不能修改
        // this 只能在成员函数内部使用
        // 只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用（后续会讲到 static 成员）。

        // this 实际上是成员函数的一个形参，在调用成员函数时将对象的地址作为实参传递给 this。不过 this 这个形参是隐式的，
        // 它并不出现在代码中，而是在编译阶段由编译器默默地将它添加到参数列表中。
        // this 作为隐式形参，本质上是成员函数的局部变量，所以只能用在成员函数的内部，并且只有在通过对象调用成员函数时才给 this 赋值。
        //
        // 在《C++函数编译原理和成员函数的实现》一节中讲到，成员函数最终被编译成与对象无关的普通函数，除了成员变量，会丢失所有信息，
        // 所以编译时要在成员函数中添加一个额外的参数，把当前对象的首地址传入，以此来关联成员函数和成员变量。
        // 这个额外的参数，实际上就是 this，它是成员函数和成员变量关联的桥梁。

        // 一个对象的this指针并不是对象本身的一部分，不会影响sizeof(对象)的结果。
        // 当在类的非静态成员函数中访问类的非静态成员的时候，编译器会自动将对象本身的地址作为一个隐含参数传递给函数。
        // 也就是说，即使你没有写上this指针，编译器在编译的时候也是加上this的，它作为非静态成员函数的隐含形参，对各成员的访问均通过this进行。
        // 例如，调用date.SetMonth(9) <===> SetMonth(&date, 9)，this 帮助完成了这一转换。

        // this指针的含义及其用法:
        // this指针是一个隐含于每一个成员函数中的特殊指针。它指向正在被该成员函数操作的那个对象。
        // 当对一个对象调用成员函数时，编译程序先将对象的地址赋给this指针，然后调用成员函数，每次成员函数存取数据成员时，由隐含使用this指针。
        // 当一个成员函数被调用时，自动向它传递一个隐含的参数，该参数是一个指向这个成员函数所在的对象的指针。
        // 在C++中，this指针被隐含地声明为: X *const this,这意味着不能给this 指针赋值；
        // 在X类的const成员函数中，this指针的类型为：const X* const, 这说明this指针所指向的这种对象是不可修改的（即不能对这种对象的数据成员进行赋值操作）;

        // this 指针的使用:
        // 一种情况就是，在类的非静态成员函数中返回类对象本身的时候，直接使用 return *this;
        // 另外一种情况是当参数与成员变量名相同时，如 this->n = n （不能写成 n = n ）。
        // 在 class 定义时不知道变量名，就用 this 这样的指针来使用变量自身。

        // * -----
        // A. this指针是什么时候创建的？
        // this在成员函数的开始执行前构造，在成员的执行结束后清除。但是如果class或者struct里面没有方法的话，它们是没有构造函数的，只能当做C的
        // struct使用。采用 TYPE xx的方式定义的话，在栈里分配内存，这时候this指针的值就是这块内存的地址。采用new的方式 创建对象的话，在堆里分配
        // 内存，new操作符通过eax返回分配 的地址，然后设置给指针变量。之后去调 用构造函数（如果有构造函数的话），这时将这个内存块的地址传给
        // ecx，之后构造函数里面怎么处理请 看上面的回答。

        // B. this指针存放在何处？堆、栈、全局变量，还是其他？
        // this指针会因编译器不同而有不同的放置位置。可能是栈，也可能是寄存器，甚至全局变量。在汇编级 别里面，一个值只会以3种形式出现：立即数、
        // 寄存器值和内存变量值。不是存放在寄存器就是存放在内 存中，它们并不是和高级语言变量对应的。

        // C. this指针是如何传递类中的函数的？绑定？还是在函数参数的首参数就是this指针？那么，this指针 又是如何找到“类实例后函数的”？
        // 大多数编译器通过ecx寄存器传递this指针。事实上，这也是一个潜规则。一般来说，不同编译器都会遵从一致的传参规则，否则不同编译器产生的obj
        // 就无法匹配了。在call之前，编译器会把对应的对象地址放到eax中。this是通过函数参数的首参来传递的。this指针在调用之前生成，至于“类实例后函
        // 数”，没有这个说法。类在实例化时，只分配类中的变量空间，并没有为函数分配空间。自从类的函数定义完成后，它就在那儿，不会跑的。

        // D. this指针是如何访问类中的变量的？
        // 如果不是类，而是结构体的话，那么，如何通过结构指针来访问结构中的变量呢？如果你明白这一点的话，就很容易理解这个问题了。在C++中 ,类和
        // 结构是只有一个区别的：类的成员默认是private，而结构是public。this是类的指针，如果换成结构，那this就是结构的指针了。

        // F. 每个类编译后，是否创建一个类中函数表保存函数指针，以便用来调用函数？
        // 普通的类函数（不论是成员函数，还是静态函数）都不会创建一个函数表来保存函数指针。只有虚函数才会被放到函数表中。但是，即使是虚函数，如
        // 果编译器能明确知道调用的是哪个函数，编译器就不会通过函数表中的指针来间接调用，而是会直接调用该函数。

        // * -----
        // 关于this指针的一个精典回答:
        // 当你进入一个房子后，
        // 你可以看见桌子、椅子、地板等，
        // 但是房子你是看不到全貌了。
        // 对于一个类的实例来说，
        // 你可以看到它的成员函数、成员变量，
        // 但是实例本身呢？
        // this是一个指针，它时时刻刻指向你这个实例本身。
    }

    else if // this 指針 return *this;
    {
        // #include <iostream>
        // #include <stdio.h>
        // #include <string.h>

        using std::cin;
        using std::cout;
        using std::endl;

        class Person {
        public:
            Person(const char *n, int a);
            Person &add_age(int a);
            int get_age();

        private:
            char *name;
            int age;
        };

        Person::Person(const char *n, int a) {
            name = new char[ strlen(n) + 1 ]; // 这里的 name 等价于 this->name
            strcpy(name, n);                  // 这里的 name 等价于 this->name
            age = a;                          // 这里的 age  等价于 this->age
        }
        Person &Person::add_age(int a) {
            age += a;
            return *this; // 返回本对象的引用
        }
        int Person::get_age() { return age; }

        void TestPerson() {
            Person ZhangSan("ZhangSan", 20);
            cout << "ZhangSan.age     = " << ZhangSan.get_age() << "\n"
                 << "ZhangSan.add_age = " << ZhangSan.add_age(1).get_age() << "\n"
                 << endl;
        }

        int main() {
            TestPerson();

            system("pause");
            return 0;
        }
        // ! res :
        // ZhangSan.age     = 20
        // ZhangSan.add_age = 21
    }

    else if // this 指針 位址測試
    {
        // this 虽然用在类的内部，但是只有在对象被创建以后才会给 this 赋值，并且这个赋值的过程是编译器自动完成的，不需要用户干预，
        // 用户也不能显式地给 this 赋值。本例中，this 的值和 pstu 的值是相同的。

        // !| 測試 1 -----
        // #include "pch.h"

        class Student {
        public:
            void SetName(const char *name);
            void SetAge(int set_age);
            void PrintThis(); // this 位址測試
            void Show();

        private:
            const char *name;
            int age;
        };

        void Student::SetName(const char *name) { this->name = name; }            // 重名, 必須使用 this
        void Student::SetAge(int set_age) { age = set_age; }                      // 不重名, 可不用 this, 但其實有隱式調用
        void Student::PrintThis() { cout << " this Address : " << this << endl; } // this 位址測試
        void Student::Show() { cout << "name : " << this->name << ", age : " << this->age << endl; }

        int main() {
            Student *pstu  = new Student;
            Student *pstu1 = new Student;
            Student *pstu2 = new Student;

            pstu->SetName("Gary");
            pstu->SetAge(16);
            pstu->Show();

            // this 位址測試
            cout << "pstu1 Address : " << pstu1 << endl;
            pstu1->PrintThis();
            cout << "pstu2 Address : " << pstu2 << endl;
            pstu2->PrintThis();

            delete pstu, pstu1, pstu2;

            system("pause");
            return 0;
        }
        // res:
        // 0xe11a10
        // 0xe11a10
        // 0xe11a50
        // 0xe11a50
        // 可以发现，this 确实指向了当前对象，而且对于不同的对象，this 的值也不一样。

        // !| 測試 2 -----
        // #include <iostream>
        // #include <stdio.h>
        // #include <string.h>

        using std::cin;
        using std::cout;
        using std::endl;

        class Location {
        public:
            void init(int x, int y);
            void assign(Location &pointer);
            int GetX();
            int GetY();

        private:
            int X, Y;
        };

        void Location::init(int x, int y) { X = x, Y = y; }
        void Location::assign(Location & pointer) {
            if (&pointer != this) { X = pointer.X, Y = pointer.Y; }
        } // 同一对象之间的赋值没有意义，所以要保证 pointer 不等于 this
        int Location::GetX() { return X; }
        int Location::GetY() { return Y; }

        int main() {
            Location x;
            Location y;
            x.init(5, 4);
            y.assign(x);

            cout << "x.X = " << x.GetX() << ", x.Y = " << x.GetY() << "\n"
                 << "y.X = " << y.GetX() << ", y.Y = " << y.GetY() << endl;

            system("pause");
            return 0;
        }
        // ! res :
        // x.X = 5, x.Y = 4
        // y.X = 5, y.Y = 4
    }
}

if // 重載(多載)
{
    // C++ 允許在同一作用域中的某個函數和運算符指定多個定義，分別稱為函數重載和運算符重載
    //
    // 重載聲明是指一個與之前已經在該作用域內聲明過的函數或方法具有相同名稱的聲明
    // 但是它們的參數列表和定義（實現）不相同
    //
    // 當您調用一個重載函數或重載運算符時，編譯器通過把您所使用的參數類型與定義中的參數類型進行比較
    // 決定選用最合適的定義。選擇最合適的重載函數或重載運算符的過程，稱為重載決策

    else if // 重載函數
    {
        // 在同一個作用域內，可以聲明多個功能類似的同名函數
        // 但是這些同名函數的形式參數（參數的 個數、類型、順序）必須不同
        // 不能僅通過返回類型的不同來重載函數
        // !| ----- 同名函數 print() 被用於輸出不同的數據類型
        // #include "pch.h"

        class Print {
        public:
            void Print(double var) { cout << "double : " << var << endl; }
            void Print(string str) { cout << "string : " << str << endl; }
        } Print;

        int main() {
            Print.Print(500.263);
            Print.Print("C++");

            system("pause");
            return 0;
        }
    }

    else if // (可/不可) 重載運算符
    {
        // 可重載:
        //
        // +, -, *, /, %
        // ==, !=, <, >, <, >=
        // ||, &&, !
        // +, -, *, &
        // ++, --
        // |, &, ~, ^, <<, >>
        // =, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=
        // new, delete, new[ ] , delete[]
        // (), ->, ,, []

        // 不可重載:
        //
        // .
        // .*, ->*
        // ::
        // sizeof
        // 條件運算符 ?:
        // 預處理符號 #
    }

    else if // operator 運算子重載
    {
        else if // 運算子重載 基礎
        {
            // 您可以重定義或重載大部分 C++ 內置的運算符
            // 與其他函數一樣，重載運算符有一個返回類型和一個參數列表
            // operator+(要重載的運算符符號)
            // !| e.g. -----
            Box operator+(const Box &Box_1);

            // 聲明加法運算符用於把兩個 Box 對象相加，返回最終的 Box 對象
            // 大多數的重載運算符可被定義為普通的非成員函數或被定義為 class 成員函數
            // 如果定義的函數為 class 的非成員函數，那麼我們需要為每次操作傳遞兩個參數，如下所示：
            Box operator+(const Box &Box_1, const Box &Box_2);

            // 為了區分前置後置，後置版本加一個 int 作為區分，但形參為 0 ，在函數中用不到
            Test operator++() { var_ = ++var; }
            Test operator++(int) { var_ = var++; } // 後置版本加一個 int

            // 運算重載符：
            // 不可以改變語法結構
            // 不可以改變操作數的個數
            // 不可以改變優先級
            // 不可以改變結合性
        }

        else if // 運算子重載 e.g.
        {
            else if // 運算子重載 - 取負 (一元运算符)
            {
                // !| -----
                // #include "pch.h"

                class Distance {
                public:
                    Distance(int var1, int var2) {
                        var1_ = var1;
                        var2_ = var2;
                    }
                    Distance operator-() {
                        var1_ = -var1_;
                        var2_ = -var2_;
                        return Distance(var1_, var2_);
                    }
                    void Print() { cout << "var1 : " << var1_ << ", var2 : " << var2_ << endl; }

                private:
                    int var1_;
                    int var2_;
                };

                int main() {
                    Distance Distance_1(1, 2);
                    Distance Distance_2(-13, 4);

                    -Distance_1; // 取相反數
                    Distance_1.Print();

                    -Distance_2; // 取相反數
                    Distance_2.Print();

                    system("pause");
                    return 0;
                }
            }

            else if // 運算子重載 + 相加 (二元运算符)
            {
                // #include "pch.h"

                class BoxVolume {
                public:
                    void SetLength(double length) { length_ = length; }
                    void SetBreadth(double breadth) { breadth_ = breadth; }
                    void SetHeight(double height) { height_ = height; }
                    double GetVolume() { return length_ * breadth_ * height_; }

                    BoxVolume operator+(const BoxVolume &BoxVolumeOper) // 重載 + 運算符，用於把兩個 BoxVolume 對象相加
                    {
                        BoxVolume BoxVolumeSum;
                        BoxVolumeSum.length_  = this->length_ + BoxVolumeOper.length_;
                        BoxVolumeSum.breadth_ = this->breadth_ + BoxVolumeOper.breadth_;
                        BoxVolumeSum.height_  = this->height_ + BoxVolumeOper.height_;
                        return BoxVolumeSum;
                    }

                private:
                    double length_;  // 長
                    double breadth_; // 寬
                    double height_;  // 高
                } BoxVolume_1, BoxVolume_2, BoxVolume_3;

                int main() {
                    double volume = 0.0;

                    BoxVolume_1.SetLength(1.0);
                    BoxVolume_1.SetBreadth(1.0);
                    BoxVolume_1.SetHeight(1.0);
                    volume = BoxVolume_1.GetVolume();
                    cout << "Volume of BoxVolume_1 : " << volume << endl; // 1

                    BoxVolume_2.SetLength(2.0);
                    BoxVolume_2.SetBreadth(2.0);
                    BoxVolume_2.SetHeight(2.0);
                    volume = BoxVolume_2.GetVolume();
                    cout << "Volume of BoxVolume_2 : " << volume << endl; // 8

                    BoxVolume_3 = BoxVolume_1 + BoxVolume_2;
                    volume      = BoxVolume_3.GetVolume();
                    cout << "Volume of BoxVolume_3 : " << volume << endl; // 27

                    system("pause");
                    return 0;
                }
            }

            else if // 運算子重載 > 大於 (关系运算符)
            {
                // #include "pch.h"

                class Age {
                public:
                    Age(int age) { this->age_ = age; }
                    inline bool operator>(const Age &Age_n) {
                        if (this->age_ > Age_n.age_) {
                            return true;
                        } else {
                            return false;
                        }
                    }

                private:
                    int age_;
                };

                int main() {
                    Age Age_1(20);
                    Age Age_2(10);

                    if (Age_1 > Age_2) { cout << ">" << endl; }

                    system("pause");
                    return 0;
                }
            }

            else if // 運算子重載 << >> (輸出入運算符)
            {
                // !| 不用友元，怪異輸出 -----
                // #include "pch.h"

                class Distance {
                public:
                    Distance() { var1_ = 0, var2_ = 0; }
                    Distance(int var1, int var2) { var1_ = var1, var2_ = var2; }
                    ostream &operator<<(ostream &os) {
                        os << "var1 : " << var1_ << ", var2 : " << var2_ << endl;
                        return os;
                    }

                private:
                    int var1_, var2_;
                };

                int main() {
                    Distance Distance1(20, 18);
                    Distance1 << cout; // == Distance1.operator<<(cout)
                    Distance1 << cout << "XXX" << endl;

                    system("pause");
                    return 0;
                }

                // !| 使用友元 -----
                // #include "pch.h"

                class Distance {
                public:
                    Distance() { var1_ = 0, var2_ = 0; }
                    Distance(int var1, int var2) { var1_ = var1, var2_ = var2; }

                    // 在 class 外使用 io 所以要用 friend
                    friend istream &operator>>(istream &input, Distance &Distance) {
                        cout << "Enter Distance.var1_ : ";
                        input >> Distance.var1_;
                        cout << "Enter Distance.var2_ : ";
                        input >> Distance.var2_;
                        return input;
                    }
                    friend ostream &operator<<(ostream &output, const Distance &Distance) {
                        output << "var1 : " << Distance.var1_ << ", var2 : " << Distance.var2_;
                        return output;
                    }

                private:
                    int var1_, var2_;
                };

                int main() {
                    Distance Distance_1(10, 11);
                    Distance Distance_2(12, 13);
                    Distance Distance_3;

                    cin >> Distance_3;

                    cout << "Distance_1 : " << Distance_1 << endl;
                    cout << "Distance_2 : " << Distance_2 << endl;
                    cout << "Distance_3 : " << Distance_3 << endl;

                    system("pause");
                    return 0;
                }
            }

            else if // 運算子重載 ++ --
            {
                // #include "pch.h"

                class Time {
                public:
                    Time() { hours_ = 0, minutes_ = 0; }
                    Time(int hour, int minutes) { hours_ = hour, minutes_ = minutes; }

                    void Print() { cout << "hours_ : " << hours_ << ", minutes_ : " << minutes_ << endl; }

                    Time operator++() {
                        ++minutes_;
                        if (minutes_ >= 60) {
                            ++hours_;
                            minutes_ -= 60;
                        }
                        return Time(hours_, minutes_);
                    } // 前缀递增
                    Time operator++(int) {
                        ++minutes_;
                        if (minutes_ >= 60) {
                            ++hours_;
                            minutes_ -= 60;
                        }
                        return Time(hours_, minutes_);
                    } // 后缀递增

                private:
                    int hours_, minutes_;
                };

                int main() {
                    Time Time1(11, 59);

                    ++Time1;
                    Time1.Print();

                    Time1++;
                    Time1.Print();

                    system("pause");
                    return 0;
                }
            }

            else if // 運算子重載 () 函數調用運算符
            {
                // #include "pch.h"

                class Distance {
                public:
                    Distance() { var1_ = 0, var2_ = 0; }
                    Distance(int feet, int inches) { var1_ = feet, var2_ = inches; }
                    Distance operator()(int a, int b, int c) {
                        Distance Distance;
                        Distance.var1_ = a + 1;
                        Distance.var2_ = b + 2;
                        return Distance;
                    }
                    void displayDistance() { cout << "feet : " << var1_ << ", inches : " << var2_ << endl; }

                private:
                    int var1_, var2_;
                };

                int main() {
                    Distance Distance_1(10, 10);
                    Distance Distance_2;

                    cout << "Distance_1 : ";
                    Distance_1.displayDistance(); // 10, 10

                    Distance_2 = Distance_1(20, 20, 20); // invoke operator()
                    cout << "Distance_2 : ";
                    Distance_2.displayDistance(); // 21, 22
                    cout << "Distance_1 : ";
                    Distance_1.displayDistance(); // 10, 10

                    system("pause");
                    return 0;
                }
            }

            else if // 運算子重載 [] (下標運算符(陣列)
            {
                // #include "pch.h"

                const int kSize = 10;

                class Array {
                public:
                    Array() {
                        for (register int i = 0; i < kSize; ++i) { arr[ i ] = i; }
                    }

                    int &operator[](int i) {
                        if (i > kSize) { return arr[ 0 ]; }
                        return arr[ i ];
                    }

                private:
                    int arr[ kSize ];
                };

                int main() {
                    Array Array;

                    cout << "Array [ 2 ]  var : " << Array[ 2 ] << endl;
                    cout << "Array [ 5 ]  var : " << Array[ 5 ] << endl;
                    cout << "Array [ 12 ] var : " << Array[ 12 ] << endl;

                    system("pause");
                    return 0;
                }
            }

            else if // 運算子重載 ->
            {
                // 它被定义用于为一个类赋予"指针"行为。
                // -> 必须是一个成员函数
                // 如果使用了 -> ，返回类型必须是指针或者是 class 的对象
                // -> 通常与 * 结合使用，用于实现"智能指针"的功能
                // !| e.g. -----
                X *operator->();
                // 这些指针是行为与正常指针相似的对象，唯一不同的是，当您通过指针访问对象时，它们会执行其他的任务。
                // 比如，当指针销毁时，或者当指针指向另一个对象时，会自动删除对象。
                // 间接引用运算符 -> 可被定义为一个一元后缀运算符。也就是说，给出一个类：

                // 类 SmartPtr 的对象可用于访问类 Ptr 的成员，使用方式与指针的用法十分相似。例如：
                // !| e.g. -----
                class Ptr {};
                class SmartPtr {
                    Ptr *operator->();
                };
                void Func(SmartPtr SmartPtr1) { SmartPtr1->var = 10; } // (Ptr.operator->())->var = 10;
                // !| -----
                // Container ==> Ctnr or Cntr
                // #include "pch.h"

                static int var1 = 0;

                class Ptr {
                public:
                    void Print() { cout << var1 << endl; }
                };

                class PtrContainer { // 为 Ptr 实现一个容器
                public:
                    void PushBackPtr(Ptr *TmpPtr) { v_ptr_ctnr_.push_back(TmpPtr); } // 0 ~ 9 個 class Ptr
                    friend class SmartPtr;

                private:
                    vector<Ptr *> v_ptr_ctnr_; // <Ptr *> 是為了與 Ptr *TmpPtr 同類型
                };

                class SmartPtr { // 智能指针
                public:
                    SmartPtr(PtrContainer &TmpPtrCtnr) { SmtPtrCtnr = TmpPtrCtnr, times_ = 0; } // 0 ~ 9 個 class Ptr

                    Ptr *operator->() { return SmtPtrCtnr.v_ptr_ctnr_[ times_ ]; } // Ptr.operator->() // 0 ~ 9 個 class Ptr
                    bool operator++() {
                        if (times_ >= SmtPtrCtnr.v_ptr_ctnr_.size() - 1) { return false; } // do while 再 - 1
                        ++times_;
                        return true;
                    }
                    bool operator++(int) { return operator++(); }

                private:
                    PtrContainer SmtPtrCtnr;
                    int times_;
                };

                int main() {
                    const int kTimes = 10;
                    Ptr PtrArr[ kTimes ]; // 10 個 class Ptr
                    PtrContainer PtrCtnr;
                    for (int i = 0; i < kTimes; ++i) {
                        PtrCtnr.PushBackPtr(&PtrArr[ i ]);
                    } // 0 ~ 9 個 class Ptr

                    SmartPtr SmtPtr(PtrCtnr); // 0 ~ 9 個 class Ptr
                    do {
                        ++var1;
                        SmtPtr->Print(); // 0 ~ 9 個 class Ptr
                    } while (++SmtPtr);  // 智能指针 // ++SmtPtr 其實是 bool 型的函數，不是無窮迴圈

                    system("pause");
                    return 0;
                }
            }
        }
    }

    else if // 重載 友元 改變重載順序
    {
        // !| -----
        // #include "pch.h"

        class A {
        private:
            int _val_;

        public:
            A() { _val_ = 0; }
            A(int val) { _val_ = val; }

            A operator+(const A &obj) { return this->_val_ + obj._val_; } // a3 = a1 + a2;
            A operator+(const int b) { return A(_val_ + b); }             // a4 = a1 + int m;
            friend A operator+(const int b, A obj) { return obj + b; }    // 調用第二個重載 + 的成員函數 相當於 obj.operator+(b);

            void display() { cout << _val_ << endl; }
        };

        int main() {
            A a1(1);
            A a2(2);
            A a3, a4, a5;
            int m = 5;

            cout << "a1 = ";
            a1.display();
            cout << "a2 = ";
            a2.display();
            cout << " m = " << m << "\n"
                 << endl;

            a3 = a1 + a2; //可以交換順序，相當月a3=a1.operator+(a2);
            cout << "a1 + a2 = ";
            a3.display();

            a4 = a1 + m; //因為加了個友元函數所以也可以交換順序了。
            cout << "a1 +  m = ";
            a4.display();

            a5 = m + a1;
            cout << " m + a1 = ";
            a5.display();

            system("pause");
            return 0;
        }
    }
}

if // 多態 (多型)
{
    // 多態按字面的意思就是多種形態。當類之間存在層次結構，並且類之間是通過繼承關聯時，就會用到多態。
    // C++ 多態意味著調用成員函數時，會根據調用函數的對象的類型來執行不同的函數。

    // 编译时多态性（静态多态）：通过重载函数实现：先期联编 early binding
    // 运行时多态性（动态多态）：通过虚函数实现 ：滞后联编 late binding

    if // 多態 靜態
    {
        // !| -----
        //   #include "pch.h"

        class Shape {
        public:
            Shape(int width, int height) { width_ = width, height_ = height; }

            virtual int area() {
                // int area() {
                cout << "Parent class area :" << endl;
                return 0;
            } // 派生是 int 類型

            // 導致錯誤輸出的原因是，調用函數 area() 被編譯器設置為基類中的版本，
            // 這就是所謂的靜態多態，或靜態鏈接 - 函數調用在程序執行前就準備好了。
            // 有時候這也被稱為早綁定，因為 area() 函數在程序編譯期間就已經設置好了。
            // 因此要在 area() 的聲明前放置 virtual

            // 此時，編譯器看是是指針的內容，而不是它的類型。因此，
            // 由於 tri 和 rec 類的對象的地址存儲在* shape中，所以會調用各自的 area() 函數。
            // 正如你所看到的，每個子類都有一個函數 area() 的獨立實現。這就是多態的一般使用方式。
            // 有了多態，您可以有多個不同的類，帶有同一個名稱但具有不同實現的函數，函數的參數甚至可以是相同的。

        protected:
            int width_,
                height_;
        };

        class Rectangle : public Shape {
        public:
            Rectangle(int a, int b) : Shape(a, b) {}

            int area() {
                cout << "Rectangle class area :" << endl;
                return (width_ * height_);
            }
        };

        class Triangle : public Shape {
        public:
            Triangle(int a, int b) : Shape(a, b) {}

            int area() {
                cout << "Triangle class area :" << endl;
                return (width_ * height_ / 2);
            }
        };

        int main() {
            Shape *shape;
            Rectangle rec(10, 7);
            Triangle tri(10, 5);

            shape = &rec;  // 存儲矩形的地址
            shape->area(); // 調用矩形的求面積函數 area

            shape = &tri;  // 存儲三角形的地址
            shape->area(); // 調用三角形的求面積函數 area

            system("pause");
            return 0;
        }
        // !| -----
    }

    else if // 多態 虛函數 & 純虛函數 // pure virtual function
    {
        // 虛函數是在基類中使用關鍵字 virtual 聲明的函數。在派生類中重新定義基類中定義的虛函數時，會告訴編譯器不要靜態鏈接到該函數。
        // 我們想要的是在程序中任意點可以根據所調用的對象類型來選擇調用的函數，這種操作被稱為動態鏈接，或後期綁定。

        // 多态性指相同对象收到不同消息或不同对象收到相同消息时产生不同的实现动作。
        // C++ 运行时多态性是通过虚函数来实现的，虚函数允许子类重新定义成员函数，子类重新定义父类的做法称为 覆盖(Override)、重写。
        //
        // C++支持两种多态性：
        // 1、编译时多态性（静态多态）：重载函数 实现(先期联编 early binding)
        // 2、运行时多态性（动态多态）：  虚函数 实现(滞后联编 late  binding)
        //
        // 多态与非多态的实质区别就是函数地址是早绑定还是晚绑定。如果函数的调用，在编译器编译期间就可以确定函数的调用地址，
        // 并生产代码，是静态的，就是说地址是早绑定的。而如果函数调用的地址不能在编译器期间确定，需要在运行时才确定，这就属于晚绑定。

        // !v| e.g. 指針虛函數 -----
        // #include "pch.h"

        class Test1 {
        public:
            void Print1() { cout << "Test1" << endl; }
            virtual void Print2() { cout << "Test1" << endl; }
        };
        class Test2 : public Test1 {
        public:
            void Print1() { cout << "Test2" << endl; }
            void Print2() { cout << "Test2" << endl; }
        };

        int main() {
            Test1 *pT1 = new Test2();
            pT1->Print1(); // ! res : Test1

            Test1 *pT2 = new Test2();
            pT1->Print2(); // ! res : Test2

            system("pause");
            return 0;
        }
        // !^| e.g. 指針虛函數 -----

        class Shape {
        public:
            virtual int area() {}   // 虛函數
            virtual int area() = 0; // 純虛函數, "= 0" == 告訴編譯器，函數沒有主體
        };
        // 在基類中定義虛函數，以便在派生類中重新定義該函數。
        // 在基類中不能對虛函數給出有意義的實現，這個時候就會用到純虛函數。

        // C++ 多態意味著調用成員函數時，會根據調用函數的對象的類型來執行不同的函數；
        //
        // 形成多態必須具備三個條件：
        //
        // 1、必須存在繼承關係
        // 2、繼承關係必須有同名虛函數其中虛函數是在基類中使用關鍵字 virtual 聲明的函數，
        //    在派生類中重新定義基類中定義的虛函數時，會告訴編譯器不要靜態鏈接到該函數)
        // 3、存在基類類型的指針或引用，通過該指針或引用調用虛函數

        // 純虛函數聲明如下：
        //
        // virtual void Func() = 0; // 純虛函數
        // 用於實現多態(polymorphism)的機制。核心理念就是通過基類訪問派生類定義的函數。
        // 在类的成员函数定义前加 virtual 关键字，该函数将被作为虚函数。虚函数被继承后仍为虚函数。
        // 只有类的成员函数才能声明为虚函数，虚函数仅适用于有继承关系的类对象。普通函数不能声明为虚函数。
        // 虛函數必須實現
        // 一定沒有定義，純虛函數用來規範派生類的行為，即接口。
        // 包含純虛函數的類是抽像類，抽像類不能定義實例，但可以聲明指向實現該抽像類的具體類的指針或引用。
        // 對於虛函數來說，父類和子類有各自的版本。由多態方式調用的時候動態綁定。
        // 實現了純虛函數的子類，該純虛函數在子類中就編程了虛函數，子類的子類即孫子類可以覆蓋該虛函數，由多態方式調用的時候動態綁定。
        // 静态成员函数不能是虚函数，因为静态成员函数不受限于某个对象。
        //
        // 构造函数不能是虚函数。
        // 析構函數應當是虛函數，而且建议声明为虚函数，將調用相應對象類型的析構函數，因此，
        // 如果指針指向的是子類對象，將調用子類的析構函數，然後自動調用基類的析構函數。
        //
        // 在有動態分配堆上內存的時候，析構函數必須是虛函數，但沒有必要是純虛的。
        // 内联函数（inline）不能是虚函数，因为内联函数不能在运行中动态确定位置。
        // 友元不是成員函數，只有成員函數才可以是虛擬的，因此友元不能是虛擬函數。但可以通過讓友元函數調用虛擬成員函數來解決友元的虛擬問題。
        // 虚函数的在子类中可以被override(覆盖)、overload (重载 )

        // 拥有纯虚函数的类称为 抽象类 。抽象类不能被实例化。类的继承往往越往后越具体，
        // 相反地，越往祖先越抽象，以至于没法实例代，其实也根本没必要实例化。
        // 按照某本书上所说，之所以定义抽象类，是为了给以后的子类留下公共接口。
        //
        // 一般地，我们不希望纯虚函数的构造函数暴露。所以我们把构造函数设为 protected
        //
        // 重载函数虽同名，但其实是不同的函数，我们让其中一种成为虚函数或者纯虚函数，其它的同名函数（如果其它的都不加virtual）并不会成为虚函数或者纯虚函数。在子类中，若重载了继承过来的虚函数，那么新的重载形式（即你的在子类中定义而在父类中没有的同名函数）的函数不会是虚函数。
        // !| -----
        // #include "pch.h"

        class Shape // 基類
        {
        public:
            virtual int GetArea() = 0; // 提供接口框架的純虛函數
            void SetWidth(int width) { width_ = width; }
            void SetHeight(int height) { height_ = height; }

        protected:
            int width_;
            int height_;
        };

        // 派生類
        class Rectangle : public Shape {
        public:
            int GetArea() { return (width_ * height_); }
        };
        class Triangle : public Shape {
        public:
            int GetArea() { return (width_ * height_) / 2; }
        };

        int main() {
            Rectangle Rect;
            Triangle Tri;

            Rect.SetWidth(5);
            Rect.SetHeight(7);
            cout << "Rectangle Area: " << Rect.GetArea() << endl; // 輸出對象的面積

            Tri.SetWidth(5);
            Tri.SetHeight(7);
            cout << "Triangle Area: " << Tri.GetArea() << endl; // 輸出對象的面積

            system("pause");
            return 0;
        }
    }
}