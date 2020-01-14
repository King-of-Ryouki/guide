// ******************************
// *
// * Author   : 施冠年
// * Date     : 2019/11/15
// * Mail     : Co6901251@gmail.com
// *
// * Function :
// *
// * Java 筆記 : 物件導向篇
// *
// ******************************

public class GuideJavaClass {

    // public static void main(String[] args) {}

    public GuideJavaClass() {

        int guide_java_class = 1;

        if (guide_java_class) // SOLID(物件導向設計)
        {
            // SOLID（單一功能、開閉原則、里氏替換、介面隔離以及依賴反轉）
        }

        if (guide_java_class) // class(類)
        {
            // 封装 Encapsulation

            if (guide_java_class) // class 構造 & 析构
            {
                if (guide_java_class) // class 構造函數
                {
                    // 子类不继承构造器，但可调用（隐式或显式）。
                    //
                    // 如果父类的构造器带有参数，则在子类的构造器中显式地通过 super 关键字调用父类的构造器，并配以适当的参数列表。
                    // 如果父类的构造器没有参数，则在子类的构造器中不需要使用 super 关键字调用父类的构造器，系统会自动调用父类的无参构造器。

                    // 1、构造方法的名字和类名相同，并且没有返回值。
                    // 2、构造方法主要用于为类的对象定义初始化状态。
                    // 3、我们不能直接调用构造方法，必须通过 new 关键字来自动调用，从而创建类的实例。
                    // 4、Java 的类都要求有构造方法，如果没有定义构造方法，Java 编译器会为我们提供一个缺省的构造方法，也就是不带参数的构造方法。

                    // new 的作用
                    // 1、为对象分配内存空间。
                    // 2、引起对象构造方法的调用。
                    // 3、为对象返回一个引用。

                    // ! vvvvv e.g. 構造函數 vvvvv

                    public class Test1 {
                        public Test1(int var1) {}
                    }

                    public class Test2 {}

                    Test1 Test1 = new Test1(var1); // 構造函數
                    Test2 Test2 = new Test2();     // 無構造函數

                    // ! ^^^^^ e.g. 構造函數 ^^^^^
                }

                if (guide_java_class) // class 析构函數 finalize()
                {
                    // ! https://www.runoob.com/java/java-methods.html

                    // Java 允许定义这样的方法，它在对象被垃圾收集器析构(回收)之前调用，
                    // 这个方法叫做 finalize( )，它用来清除回收对象。
                    // 例如，你可以使用 finalize() 来确保一个对象打开的文件被关闭了。
                    // 在 finalize() 方法里，你必须指定在对象销毁时候要执行的操作。

                    public class Test3 {
                        protected void finalize() { int var1; } // protected 限定在 class 中不被誤用
                    }
                }
            }

            if (guide_java_class) // class 訪問權限
            {
                // 類　  　　 : default, public
                // 變量, 方法 : default, public, protected, private,
                //
                // default   : 同一个包
                // public    : 任何地方
                // protected : 同一个包 + 任何子类
                // private   : 自身類
            }

            if (guide_java_class) // class 訪問實例變量和方法
            {
                class Test {
                    public void Func() {}
                }

                Test test = new Test(); // 實例化對象
                test.Func();            // 訪問類中的方法
                // equal
                new Test().Func(); // 訪問類中的方法
            }

            if (guide_java_class) // 訪問控制和繼承
            {
                // 繼承規則 :
                // 父           子
                // public     = public
                // protected != private
            }
        }

        if (guide_java_class) // class extends(類 繼承)
        {
            // * Java 不支持多继承，但支持多重继承

            class Class2 extends Class1 implements Interface1 {}

            if (guide_java_class) // interface(接口) & implements(實現)
            {
                // 接口裡的
                // 變量預設 : public static final,
                // 方法預設 : public.
                //
                // default 可預設方法

                // 接口有以下特性：
                //
                // 接口中方法隐式 public abstract(只能是 public abstract，其他修饰符都会报错)
                // 接口中变量隐式 static || final (并且只能是 public)
                // 当类实现接口的时候，类要实现接口中所有的方法，否则，类必须声明为抽象的类。
                // 类在实现接口的方法时，不能抛出强制性异常，只能在接口中，或者继承接口的抽象类中抛出该强制性异常。

                // 抽象类和接口的区别
                //
                // 抽象类可以有方法体，接口要加 default
                // 接口中的变量只能是 static 和 final
                // 接口不是被类继承了，而是要被类实现。
                // 接口支持多继承。
                // 接口中不能含有静态代码块以及静态方法(用 static 修饰的方法)，而抽象类是可以有静态代码块和静态方法。
                // 一个类只能继承一个抽象类，而一个类却可以实现多个接口。

                interface Interface1 {
                    default void Func1() {
                        }
                        void Func2();
                }

                // 使用 implements 关键字可以变相的使 java 具有多继承的特性，
                // 使用范围为类继承接口的情况，可以同时继承多个接口（接口跟接口之间采用逗号分隔）。

                interface Interface2 {}

                public class Interface3 implements Interface1, Interface2 {}
            }

            if (guide_java_class) // abstract(抽象)
            {
                // abstract 需要被子类继承，而 final 作用是禁止继承的

                abstract class Class1 { // 抽象方法
                    abstract void Func1();
                }

                class Class2 extends Class1 {
                    @Override
                    void Func1() {} // 实现抽象方法
                }
            }

            if (guide_java_class) // this & spuer
            {
                //  this : 调用自己的方法(指向对象本身的指针，形参与成员名字重名，用 this 来区分。)
                // super : 调用父类的方法(超（父）类对象的一个指针。)

                class Animal {
                    void Eat() { System.out.println("Animal : eat"); }
                }

                class Dog extends Animal {

                    void eat() { System.out.println("Dog    : eat"); }

                    void eatTest() {
                        this.eat();  //  this 调用自己的方法
                        super.eat(); // super 调用父类方法
                    }
                }
            }

            if (guide_java_class) // 虚函数
            {
                // 虚函数的存在是为了多态。

                // Java 中其实没有虚函数的概念，它的普通函数就相当于 C++ 的虚函数，
                // 动态绑定是Java的默认行为。如果 Java 中不希望某个函数具有虚函数特性，
                // 可以加上 final 关键字变成非虚函数。
            }

            if (guide_java_class) // 向上轉型
            {
                // * 向上轉型(upcasting)會變成父類(丟失子類的方法)
                // *
                // * C++  會先調用父類方法，要調用子類方法需用虛函數
                // * java 會先調用子類方法(方法預設為虛函數)，使用 super 调用父类方法

                public class Test {
                    public static void main(String[] args) {
                        Class2 class2 = new Class2();
                        class2.Func1(); // ! Res :  Class2 Func1
                        class2.Func2(); // ! Res :  Class1 Func2
                    }
                }

                class Class1 {
                    public void Func1() { System.out.println("Class1 Func1"); }
                    public void Func2() { System.out.println("Class1 Func2"); }
                }

                class Class2 extends Class1 {
                    public void Func1() { System.out.println("Class2 Func1"); }
                    public void Func2() { super.Func2(); }
                }
            }
        }

        if (guide_java_class) // 繼承 & 非繼承(依賴、關聯、聚合、組合)
        {
            // * 　繼承 : 子類會有父類所有特性(is a)
            // * 非繼承 : 若有孫子類，且不想繼承父類時使用(has a)

            if (guide_java_class) // 繼承 | is a(繼承)
            {

                // * 繼承

                class Class1 {
                    public void Func1() { System.out.println("Class1.Func1()"); }
                }
                class Class2 extends Class1 {}

                // * 實現(接口)

                interface Interface1 {
                    public void Func1();
                }

                class Class2 implements Interface1 {
                    public void Func1() { System.out.println("Class2.Func1()"); }
                }
            }

            // 非繼承

            if (guide_java_class) // ! has a(依赖 ==> 关联)
            {
                // ! 關聯 聚合 基本相同
                // ! 聚合 組合 基本相同
                //
                // 依賴 ==> 類().方法(父類) // 弱依賴(方法中呼叫父類)
                // 關聯 ==> 類(父類).方法() // 強依賴(　類中呼叫父類)
                // 聚合 ==> 類(父類).方法() // ! 與關聯相似，方法可單獨存在(關聯以外的部分)，方法中可呼叫父類但不為必須(b ((has a) or (is b)))
                // 組合 ==> 類(父類).方法() // ! 與聚合相似，方法無法單獨存在(必須組合才有意義)

                if (guide_java_class) // 依賴 ==> 類().方法(父類) // 弱依賴，只在方法中呼叫父類
                {
                    class HomeWork {
                        public void DoHomeWork() { System.out.println("Do homework"); }
                    }

                    class Me {

                        // 依賴，只在方法中呼叫父類
                        public void DoHomeWork(HomeWork HomeWork) { HomeWork.DoHomeWork(); }

                        // 關聯
                        private HomeWork homeWork_;

                        public void DoHomeWork() {
                            homeWork_ = HomeWork;
                            homeWork_.DoHomeWork();
                        }
                    }
                }

                if (guide_java_class) // 關聯 & 聚合
                {
                    // 關聯 ==> 類(父類).方法() // 強依賴，方法中只能呼叫父類
                    // 聚合 ==> 類(父類).方法() // ! 與關聯相似，方法可單獨存在(關聯以外的部分)，方法中可呼叫父類但不為必須(b has a or is b)

                    class HomeWork {
                        public void DoHomeWork() { System.out.println("Do homework"); }
                    }

                    class Me {

                        // 關聯
                        private HomeWork homeWork_;

                        public void DoHomeWork() {
                            homeWork_ = HomeWork;
                            homeWork_.DoHomeWork();
                        }

                        // 一轉攻勢，突然冒出個不是只呼叫父類的(聚合(關聯以外的部分))
                        public void BurnHomeWork(WhoCare_s whoCare_s) {
                            System.out.println("小孩子才寫功課");
                        }
                    }
                }

                if (guide_java_class) // 聚合 & 组合
                {
                    class HomeWork { // 聚合(語意上，功課可以單獨存在)
                        public void DoHomeWork() { System.out.println("Do homework"); }
                    }

                    class Eye { // 組合(語意上，眼睛無法單獨存在)
                        public void Look() { System.out.println("看的你心裡發寒"); }
                    }
                    class Face {                     // 組合(語意上，眼睛無法單獨存在)
                        private Eye Eye = new Eye(); // 臉上有眼睛
                    }
                }
            }
        }
    }
}