// ******************************
// *
// * date     : 2019/10/05
// *
// * author   : 施冠年
// * mail     : Co6901251@gmail.com
// *
// * function :
// *
// * Java notes : Special
// *
// * Java 筆記  : 特殊情況篇
// *
// * 使用 VS Code 摺疊，所以會有些奇怪的用法
// *
// * 推薦使用 VS Code 擴充 : Better Comments
// *
// ******************************

public class JavaGuideSpecial {

    // public static void main(String[] args) {}

    public JavaGuideSpecial() {

        int java_guide_class = 1;

        if (java_guide_class) // [] 的位置
        {
            int[] var_3, var_4; // ! Res : array, array
            int var_1[], var_2; // ! Res : array, int
        }

        if (java_guide_class) // ++i & i++ & i += 1 & i = i + 1
        {
            // * 速度排名 :
            ++i;       // * 最快
            i++;       // * ++i + tmp
            i += 1;    // * 取址
            i = i + 1; // * 取址 + tmp

            // * ++i

            // * i++

            // * i += 1
            // 讀取左值 i 位址
            // i + 1
            // 左值 i + 1

            // * i = i + 1
            // 讀取右值 i 位址
            // i + 1
            // 讀取左值 i 位址
            // 左值 = 右值
        }

        if (java_guide_class) // For loop // ++i & i++ 語意
        {
            for (int i = 0; i < 1; i++) {} // 常見(不正確)
            for (int i = 0; i < 1; ++i) {} // 正確

            for (int i = 0; i < 1; i = 100) {
                System.out.println(i); // ! Res : 0
            }
            // for (1; 2; 3)
            // 第一次判斷只有 1, 2
            // 之後皆為 3,2
            // 因此 3 應該為 ++i
        }

        if (java_guide_class) // 判斷 + 賦值
        {
            int var_1 = 0;
            if (++var_1 == 1) { System.out.println("1"); } // ! Res : 1
        }

        if (java_guide_class) { // enum 自動賦值，與奇妙的構造函數

            enum EnumOperation {

                kAdd,
                kSub,
                kMul,
                kDiv,
                kEqual,
                kDot;

                private static class Counter { private static int next_var_ = 0; }

                private EnumOperation() {
                    this(Counter.next_var_); // ! 步驟 1
                    ++Counter.next_var_;
                }
                private EnumOperation(int var) { var_ = var; } // ! 步驟 2

                private int var_;
                public int get_var() { return var_; }
            }
            ;
        }

        if (java_guide_class) // 傳參 & 傳值
        {
            public class TestCallByValue {

                /**
                 * @param args
                 */
                public static void main(String[] args) {

                    TestCallByValue TestCallByValue = new TestCallByValue();

                    Integer var_1 = 1;
                    TestCallByValue.Func_1(var_1);
                    System.out.println(var_1); // ! res : 1

                    Integer var_2 = 1;
                    var_2         = TestCallByValue.Func_2(var_2);
                    System.out.println(var_2); // ! res : 5

                    int arr_1[] = { 0, 1, 2 };
                    TestCallByValue.Func_3(arr_1);
                    System.out.println(arr_1[ 0 ]); // ! res : 5
                }

                public void Func_1(Integer var_1) { var_1 = 5; } // ! res : 1

                public int Func_2(Integer var_1) {
                    var_1 = 5;
                    return var_1;
                } // ! res : 5

                public void Func_3(int arr_1[]) { arr_1[ 0 ] = 5; } // ! res : 5
            }
        }

        if (java_guide_class) // == && equals()
        {

            // 基本類型 : ==     值
            // 引用類型 : ==     地址
            // 引用類型 : equals 值

            // * 只要其中一個為基本類型 : == 比值

            // * Object.class equals() 實現
            // public boolean equals(Object obj) {
            //     return (this == obj); // ! 地址
            // }

            // * Integer.class equals() 實現
            // public boolean equals(Object obj) {
            //     if (obj instanceof Integer) {
            //         return value == ((Integer) obj).intValue(); // ! 值
            //     }
            //     return false;
            // }
        }

        if (java_guide_class) // Java 讀取中文路徑(UTF-8)
        {
            File file = new File(URLDecoder.decode(dir_path, "UTF-8"));
        }

        if (java_guide_class) //
        {
        }

        if (java_guide_class) //
        {
        }
    }
}