// JavaGuideDecompile 反編譯

// bytecode(字節碼 / 位元組碼)

// * 原始碼

package test;

import java.io.*;
import java.util.*;

public class Test {

    /**
     * @param args
     */
    public static void main(String args[]) {

        int var_1 = 1;
        ++var_1;
        var_1++;
        System.out.println(var_1);

    }
}

// * 反編譯

// Compiled from Test.java (version 11 : 55.0, super bit)
public class test.Test {

    // Method descriptor #7 ()V
    // Stack: 1, Locals: 1
    public Test();
      0  aload_0 [this]
      1  invokespecial java.lang.Object() [1]
      4  return
        Line numbers:
          [pc: 0, line: 6]

    // Method descriptor #11 ([Ljava/lang/String;)V
    // Stack: 2, Locals: 2
    public static void main(java.lang.String[] arg0);
       0  iconst_5
       1  istore_1
       2  getstatic java.lang.System.out : java.io.PrintStream [2]
       5  iinc 1 1
       8  iload_1
       9  invokevirtual java.io.PrintStream.println(int) : void [3]
      12  getstatic java.lang.System.out : java.io.PrintStream [2]
      15  iload_1
      16  iinc 1 1
      19  invokevirtual java.io.PrintStream.println(int) : void [3]
      22  return
        Line numbers:
          [pc: 0, line: 13]
          [pc: 2, line: 14]
          [pc: 12, line: 15]
          [pc: 22, line: 17]
  }

// * int 賦值指令 :
// iconst : -1 ~ 5
// bipush : -128 ~ 127
// sipush : -32768 ~ 32767
// ldc    : -2147483648 ~ 2147483647

// * 說明 :
// iconst_1, iinc 1 等... // i 指的是變數類型, double 則是 d.
//
// * 0  iconst_5 // 賦值 5
// * 1  istore_1 // 儲存賦值, 1 為變數編號
// * 5  iinc 1 1 // 變數編號 1 的值 + 1, inc 推測為 increase
// * 8  iload_1  // 讀取變數編號 1

var_1 += 2; // 2  iinc 1 2

++var_1;    // 先加，再讀
            //  8  iinc 1 1
            // 11  iload_1

var_1++;    // 先讀，再加
            // 18  iload_1
            // 19  iinc 1 1