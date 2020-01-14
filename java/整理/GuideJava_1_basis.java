// java_guide_1_basis 基礎篇

public class java_guide_1_basis {

    // public static void main(String[] args) {}

    int java_guide_class = 1;

    public java_guide_1_basis() {

        if (x) // 源文件声明规则
        {
            // 在本节的最后部分，我们将学习源文件的声明规则。当在一个源文件中定义多个类，并且还有import语句和package语句时，要特别注意这些规则。
            //
            // 一个源文件中只能有一个public类
            // 一个源文件可以有多个非public类
            //
            // 源文件的名称和public类的类名。
            // 如果一个类定义在某个包中，那么package语句应该在源文件的首行。
            // 如果源文件包含import语句，那么应该放在package语句和类定义之间。如果没有package语句，那么import语句应该在源文件中最前面。
            // import语句和package语句对源文件中定义的所有类都有效。在同一源文件中，不能给不同的类不同的包声明。

            // 类有若干种访问级别，并且类也分不同的类型：抽象类和final类等。这些将在访问控制章节介绍。
            // 除了上面提到的几种类型，Java还有一些特殊的类，如：内部类、匿名类。

            // package 的作用就是 c++ 的 namespace 的作用，防止名字相同的类产生冲突。Java 编译器在编译时，
            // 直接根据 package 指定的信息直接将生成的 class 文件生成到对应目录下。
            // 如 package aaa.bbb.ccc 编译器就将该 .java 文件下的各个类生成到 ./aaa/bbb/ccc/ 这个目录。
            //
            // import 是为了简化使用 package 之后的实例化的代码。假设 ./aaa/bbb/ccc/ 下的 A 类，假如没有 import，
            // 实例化A类为：new aaa.bbb.ccc.A()，使用 import aaa.bbb.ccc.A 后，就可以直接使用 new A() 了，
            // 也就是编译器匹配并扩展了 aaa.bbb.ccc. 这串字符串。
        }

        if (x) // package 包
        {
            // package 的作用就是 c++ 的 namespace 的作用，防止名字相同的类产生冲突。
            // Java 编译器在编译时，直接根据 package 指定的信息直接将生成的 class 文件生成到对应目录下。
            // 如 package aaa.bbb.ccc 编译器就将该 .java 文件下的各个类生成到 ./aaa/bbb/ccc/ 这个目录。

            // import 是为了简化使用 package 之后的实例化的代码。
            // 假设 ./aaa/bbb/ccc/ 下的 A 类，假如没有 import，
            //
            // 实例化A类为： new aaa.bbb.ccc.A()，
            // 使用 import aaa.bbb.ccc.A 后，就可以直接使用 new A() 了，
            // 也就是编译器匹配并扩展了 aaa.bbb.ccc. 这串字符串。

            // Java 中带包（创建及引用）的类的编译
            // 只有一个文件时编译：
            // javac A.java
            //
            // 一个包的文件都在时编译：
            // javac -d . *.java
            //
            // 运行：编译之后会自己生成文件夹，不要进入这个文件夹，直接运行 java -cp /home/test test.Run，
            // 其中源文件在 test 文件夹中，包名为 test，启动文件为 Run.java。
        }

        if (x) // 多文件
        {
            // java因强制要求类名（唯一的public类）和文件名统一，因此在引用其它类时无需显式声明。
            // 在编译时，编译器会根据类名去寻找同名文件。
        }

        if (x) // 編碼錯誤
        {
            // 错误： CMD 编译 Java 源文件时出现的编码 GBK 的不可映射字符的错误。
            // 办法：使用 javac -encoding UTF-8 .java 指定编码形式。

            // 原因：由于 JDK 是国际版的，在编译的时候，如果我们没有用 -encoding 参数指定 JAVA 源程序的编码格式，
            // 则 java.exe 首先获得我们才做系统默认采用的编码格式，也即在编译 JAVA 程序时，若我们不指定源程序文件的编码格式，
            // JDK 首先获得操作系统的 file.encoding 参数（它保存的就是操作系统默认的编码格式，如 win2k，他的值为 GBK），
            // 然后 JDK 就把我们的 JAVA 源程序从 file.encoding 编码格式转化为 JAVA 内部默认的 UNICODE 格式放到内存中。
            // 之后，javac 把转换后的 UNICODE 格式的文件进行编译成 class 类文件，此时 .class 文件是 UNICODE 编码的，
            // 它暂放在内存中，紧接着，JDK 将此以 UNICODE 编码编译后的 .class 文件保存到操作系统中形成我们见到的 .class 文件。
            // 但我们不加设置就编译时，相当于使用了参数: javac -encoding gbk xx.java，就会出现不兼容的情况。
        }

        if (x) // 枚举
        {
            // * 注意：枚举可以单独声明或者声明在类里面。方法、变量、构造函数也可以在枚举中定义。

            // ! vvvvv e.g. 枚举 vvvvv

            class FreshJuice {
                enum EnumSize {
                    SMALL,
                    MEDIUM,
                    LARGE
                }

                EnumSize size;
            }

            public class FreshJuiceTest {

                public static void main(String[] args) {

                    FreshJuice juice = new FreshJuice();

                    juice.size = FreshJuice.EnumSize.MEDIUM;
                }
            }

            // ! ^^^^^ e.g. 枚举 ^^^^^
        }

        if (x) // 控制台输出入 IO
        {
            // ! https://www.runoob.com/java/java-files-io.html

            if (x) { // 控制台输入

                // Java 的控制台输入由 System.in 完成。
                // 为了获得一个绑定到控制台的字符流，你可以把 System.in 包装在一个 BufferedReader 对象中来创建一个字符流。
                // 下面是创建 BufferedReader 的基本语法：
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                // BufferedReader 对象创建后，我们便可以使用 read() 方法从控制台读取一个字符，或者用 readLine() 方法读取一个字符串。

                // 从控制台读取多字符输入
                // 从 BufferedReader 对象读取一个字符要使用 read() 方法，它的语法如下：
                // * int read() throws IOException
                // 每次调用 read() 方法，它从输入流读取一个字符并把该字符作为整数值返回。 当流结束的时候返回 -1。该方法抛出 IOException。

                if (x) { // 使用 BufferedReader 在控制台读取字符

                    // 下面的程序示范了用 read() 方法从控制台不断读取字符直到用户输入 "q"。

                    // ! ^^^^^ e.g. 使用 BufferedReader 在控制台读取字符 ^^^^^
                    // import java.io.*;

                    public class BRRead {
                        public static void main(String args[]) throws IOException {

                            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                            System.out.println("input 'q' to exit");

                            char str_1;

                            do {

                                str_1 = (char) br.read();
                                System.out.println(str_1);

                            } while (str_1 != 'q');
                        }
                    }
                    // !^| e.g. 使用 BufferedReader 在控制台读取字符 ^^^^^
                }

                if (java_guide_class) // BufferedWriter
                {
                    // 輸出流
                    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
                    bw.close();

                    // 文件
                    BufferedWriter out = new BufferedWriter(new FileWriter("Test.txt"));
                    out.write("Test");
                    out.close();
                }

                if (x) { // BufferedReader & Scanner

                    // BufferedReader 速度快，直接讀取(為字符，轉換麻煩)
                    // 處理 IOException

                    // Scanner        缓冲区 1KB, 非同步
                    // BufferedReader 缓冲区 8KB, 　同步

                    // Scanner 不仅能从输入流中读取，也能从文件中读取

                    // ! ^^^^^ e.g. Scanner ^^^^^
                    // import java.util.Scanner;

                    public class ScannerDemo {
                        public static void main(String[] args) {

                            Scanner scan = new Scanner(System.in); // 控制台讀取
                            // Scanner sc = new Scanner(new File("test.txt")); // 文件读取
                            System.out.println("next方式接收：");

                            if (scan.hasNext()) { // 判断是否还有输入
                                String str1 = scan.next();
                                System.out.println("输入的数据为：" + str1);
                            }

                            scan.close();
                        }
                    }
                    // !^| e.g. Scanner ^^^^^
                }

                if (x) { // console

                    // 输入的时候字符都是可见的，所以Scanner类不适合从控制台读取密码。
                    // 从Java SE 6开始特别引入了Console类来实现这个目的。

                    // 若要读取一个密码，可以采用下面这段代码：
                    Console cons    = System.console();
                    String username = cons.readline("User name: ");
                    char[] passwd   = cons.readPassword("Password: ");

                    // 为了安全起见，返回的密码存放在一维字符数组中，而不是字符串中。
                    // 在对密码进行处理之后，应该马上用一个填充值覆盖数组元素。

                    // 采用Console对象处理输入不如采用Scanner方便。
                    // 每次只能读取一行输入，而没有能够读取一个单词或者一个数值的方法。
                }

                if (x) { // StringTokenizer

                    // StringTokenizer类可以分解输入的整行得到的带空格的字符串。
                    // 默认情况下，StringTokenizer以空格，制表符，换行符和回车符作为分割依据。

                    // ! ^^^^^ e.g. StringTokenizer ^^^^^
                    // import java.util.Scanner;
                    // import java.util.StringTokenizer;

                    class Main {
                        public static void main(String[] args) {

                            Scanner scanner = new Scanner(System.in);
                            System.out.println("输入数据：");

                            StringTokenizer stringTokenizer = new StringTokenizer(scanner.nextLine());
                            System.out.println("分隔后：");

                            while (stringTokenizer.hasMoreTokens()) {
                                System.out.println(stringTokenizer.nextToken());
                            }
                        }
                    }
                    // !^| e.g. StringTokenizer ^^^^^
                }
            }

            if (x) // 控制台输出
            {
                // 控制台的输出由 print() 和 println() 完成。这些方法都由类 PrintStream 定义，System.out 是该类对象的一个引用。
                // PrintStream 继承了 OutputStream类，并且实现了方法 write()。这样，write() 也可以用来往控制台写操作。
                // * void write(int byteval);
                // ! write() 方法不经常使用，因为 print() 和 println() 方法用起来更为方便。
            }
        }

        if (x) // FileInputStream | FileOutputStream | DataInputStream | DataOutputStream
        {
            // ! File Class(类)
            // ! FileReader Class(类)
            // ! FileWriter Class(类)
            // http://www.runoob.com/java/java-files-io.html

            // * FileInputStream
            // 该流用于从文件读取数据
            InputStream f = new FileInputStream("C:/java/hello");
            // or
            File f          = new File("C:/java/hello");
            InputStream out = new FileInputStream(f);

            // * FileOutputStream
            // 该类用来创建一个文件并向文件中写数据。
            // 如果该流在打开文件进行输出前，目标文件不存在，那么该流会创建该文件。
            OutputStream f = new FileOutputStream("C:/java/hello");
            // or
            File f         = new File("C:/java/hello");
            OutputStream f = new FileOutputStream(f);

            // * ^^^^^

            // ! 读写文件中出现乱码, 跟字符集编码无关, 是由于读写的格式不同导致的
            // ! System.out.print((byte) is.read() + " "); // 强转为byte类型就好了

            // 该流用于从文件读取数据，它的对象可以用关键字 new 来创建。
            // 有多种构造方法可用来创建对象。
            // 可以使用字符串类型的文件名来创建一个输入流对象来读取文件：
            InputStream f = new FileInputStream("C:/java/hello");

            // 也可以使用一个文件对象来创建一个输入流对象来读取文件。我们首先得使用 File() 方法来创建一个文件对象：
            File F          = new File("C:/java/hello");
            InputStream out = new FileInputStream(f);

            if (x) // ! e.g. 轉大寫 DataOutputStream
            {
                public class Test2 {

                    // javac -encoding utf-8 java_src\\Test2.java
                    // java -cp E:\program\src\java\java_src Test2

                    /**
                     * @param args
                     */
                    public static void main(String args[]) throws IOException {

                        DataInputStream IPS  = new DataInputStream(new FileInputStream("test.txt"));
                        DataOutputStream OPS = new DataOutputStream(new FileOutputStream("test1.txt"));

                        BufferedReader BR = new BufferedReader(new InputStreamReader(IPS));

                        String str_1;
                        while ((str_1 = BR.readLine()) != null) {
                            String u = str_1.toUpperCase();
                            System.out.println(u);
                            OPS.writeBytes(u + "  ,");
                        }

                        BR.close();
                        OPS.close();
                        IPS.close();
                    }
                }
            }

            if (x) // ! e.g. 資料寫入檔案 & 輸出至控制台
            {
                public class Test2 {
                    /**
                     * @param args
                     */
                    public static void main(String[] args) throws IOException {

                        File File_1 = new File("a.txt");

                        FileOutputStream FOPS     = new FileOutputStream(File_1);          // 构建FileOutputStream对象,文件不存在会自动新建
                        OutputStreamWriter writer = new OutputStreamWriter(FOPS, "UTF-8"); // 构建OutputStreamWriter对象,参数可以指定编码,默认为操作系统默认编码,windows上是gbk

                        writer.append("中文輸入");
                        writer.append("\r\n"); // 換行
                        writer.append("English");
                        writer.close();

                        FOPS.close(); // 关闭输出流,释放系统资源

                        FileInputStream FIPS   = new FileInputStream(File_1);
                        InputStreamReader IPSR = new InputStreamReader(FIPS, "UTF-8"); // 编码与写入相同

                        StringBuffer SB = new StringBuffer();

                        while (IPSR.ready()) {
                            SB.append((char) IPSR.read()); // 转成char加到StringBuffer对象中
                        }

                        System.out.println(SB.toString());

                        IPSR.close(); // 关闭读取流
                        FIPS.close(); // 关闭输入流,释放系统资源
                    }
                }
            }

            if (x) // ! e.g. 搜尋指定附檔名
            {
                public class Test2 implements FilenameFilter { // 此次使用本类作为接口

                    /**
                     * @param args
                     */
                    public void f() {

                        File f            = new File("E:\\Myworkspace\\08\\src");
                        String[] filename = f.list(); // 以字符串的形式，先列出当前目录下所有文件看一下（有什么类型的文件）

                        for (int i = 0; i < filename.length; ++i) {
                            System.out.println(filename[ i ]);
                        }

                        System.out.println("********************************");

                        String[] fname = f.list(this);
                        for (int i = 0; i < fname.length; ++i) {
                            System.out.println(fname[ i ]);
                        }
                    }

                    public static void main(String[] args) {
                        // TODO Auto-generated method stub
                        new Test2().f();
                    }

                    @Override
                    public boolean accept(File f, String name) { // 重写接口方法
                        // TODO Auto-generated method stub
                        return name.endsWith(".java"); // 返回当前目录下以.java结尾的文件
                    }
                }
            }

            if (x) // ! e.g. mp3 檔案合併
            {
                // ******************************
                // *
                // * http://www.runoob.com/java/java-files-io.html
                // *
                // * 自己写了一个简单的小程序用来剪辑特定长度的音频，并将它们混剪在一起，大体思路是这样的：
                // *
                // * 1. 使用 FileInputStream 输入两个音频
                // * 2. 使用 FileInputStream的skip(long n) 方法跳过特定字节长度的音频文件，比如说：输入
                // skip(1024*1024*3)，这样就能丢弃掉音频文件前面的 3MB 的内容。
                // * 3. 截取中间特定长度的音频文件：每次输入 8KB 的内容，使用 count 记录输入次数，达到设置的次数就终止音频输入。比如说要截取 2MB
                // 的音频，每次往输入流中输入 8KB 的内容，就要输入 1024*2/8 次。
                // * 4. 往同一个输出流 FileOutputStream 中输出音频，并生成文件，实现音频混合。
                // *
                // ******************************

                // javac -encoding utf-8 java_src\\MusicCompound.java
                // java -cp E:\program\src\java\java_src MusicCompound

                public class MusicCompound {
                    public static void main(String args[]) {

                        String FileNames[] = { "E:/program/src/java/java_src/星月神话.mp3",
                                               "E:/program/src/java/java_src/我只在乎你.mp3" };
                        byte arr_byte_1[]  = new byte[ 1024 * 8 ]; // 设置byte数组，每次往输出流中传入8K的内容

                        FileOutputStream FOPS = null;
                        FileInputStream FIPS  = null;

                        try {

                            FOPS = new FileOutputStream("E:/program/src/java/java_src/合并.mp3");

                            for (int i = 0; i < 2; ++i) {

                                FIPS = new FileInputStream(FileNames[ i ]);
                                FIPS.skip(1024 * 1024 * 3); // 跳过前面3M的歌曲内容

                                int count = 0;
                                while (FIPS.read(arr_byte_1) != -1) {
                                    FOPS.write(arr_byte_1);
                                    ++count;
                                    // System.out.println(count);

                                    if (count == (1024 * 2 / 8)) { // 要截取中间2MB的内容，每次输入8k的内容，所以输入的次数是1024*2/8
                                        break;
                                    }
                                }
                            }

                        } catch (FileNotFoundException e) {
                            e.printStackTrace();
                        } catch (IOException e) {
                            e.printStackTrace();
                        } finally {

                            try {
                                // 输出完成后关闭输入输出流
                                FIPS.close();
                                FOPS.close();
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                        }
                    }
                }
            }
        }

        if (x) // 目录 & 文件
        {
            if (x) // 创建目录 | 文件夹
            {
                // File类中有两个方法可以用来创建文件夹：
                //
                // mkdir()方法创建一个文件夹，成功则返回true，失败则返回false。
                // 失败表明File对象指定的路径已经存在，或者由于整个路径还不存在，该文件夹不能被创建。
                //
                // mkdirs()方法创建一个文件夹和它的所有父文件夹。

                if (x) // ! e.g. 创建目录
                {
                    public class CreateDir {
                        public static void main(String args[]) {
                            String dirname = "/tmp/user/java/bin"; // 创建目录 "/tmp/user/java/bin"
                            File d         = new File(dirname);

                            d.mkdirs(); // 创建目录
                        }
                    }
                }
            }

            if (x) // 读取目录 | 文件夹
            {
                // 一个目录其实就是一个 File 对象，它包含其他文件和文件夹。
                // 如果创建一个 File 对象并且它是一个目录，那么调用 isDirectory() 方法会返回 true。
                // 可以通过调用该对象上的 list() 方法，来提取它包含的文件和文件夹的列表。
                // 下面展示的例子说明如何使用 list() 方法来检查一个文件夹中包含的内容：

                public class Test2 {
                    /**
                     * @param args
                     */
                    public static void main(String args[]) {

                        String dirname = "/tmp";
                        File f1        = new File(dirname);

                        if (f1.isDirectory()) {

                            System.out.println("目录 " + dirname);

                            String s[] = f1.list();
                            for (int i = 0; i < s.length; i++) {

                                File f = new File(dirname + "/" + s[ i ]);

                                if (f.isDirectory()) {
                                    System.out.println(s[ i ] + " 是一个目录");
                                } else {
                                    System.out.println(s[ i ] + " 是一个文件");
                                }
                            }

                        } else {

                            System.out.println(dirname + " 不是一个目录");
                        }
                    }
                }
            }

            if (x) // 删除目录或文件
            {
                // 删除文件可以使用 java.io.File.delete() 方法。
                // 当删除某一目录时，必须保证该目录下没有其他文件才能正确删除，否则将删除失败。

                if (x) // ! e.g. 删除目录或文件
                {
                    public class DeleteFileDemo {
                        public static void main(String args[]) {
                            File folder = new File("/tmp/java/"); // 这里修改为自己的测试目录
                            deleteFolder(folder);
                        }

                        // 删除文件及目录
                        public static void deleteFolder(File folder) {
                            File[] files = folder.listFiles();

                            if (files != null) {
                                for (File f : files) {

                                    if (f.isDirectory()) {
                                        deleteFolder(f);
                                    } else {
                                        f.delete();
                                    }
                                }
                            }
                            folder.delete();
                        }
                    }
                }
            }
        }

        if (x) // new 创建对象
        {
            // 创建对象需要以下三步：
            //
            // 声明：声明一个对象，包括对象名称和对象类型。
            // 实例化：使用关键字new来创建一个对象。
            // 初始化：使用new创建对象时，会调用构造方法初始化对象。

            // ! vvvvv e.g.  vvvvv

            public class Puppy {
                public Puppy(String name) { System.out.println("小狗的名字是 : " + name); }
                public static void main(String[] args) { Puppy myPuppy = new Puppy("tommy"); } // 创建一个Puppy对象
            }
            // ! Res : 小狗的名字是 : tommy

            // ! ^^^^^ e.g.  ^^^^^
        }

        if (java_guide_class) // 包装类
        {
            // Integer 是一个引用类型, 而一个 int 是一个值类型

            // 二):以List为例,大家都知道一个动态数组的add(Object o)方法只能接受一个引用类型，即一个对象，
            // 而怎样把一个数字放到一个动态数组里面...,相信到这里你已经明白了为什么一个值类型会有一个对应的包装类了吧。

            // 三):包装类还有一个重要的功能，就是适配器，这里以一个String类型--->到Integer类型,
            // 我们知道要想把一个String类型转换一个int类型的数据,new Integer(String).intValue();
            // 或者直接调用它的静态方法Integer.parse(String)方法
        }

        if (java_guide_class) // String StringBuffer StringBuilder
        {
            // String：字符串常量，字符串长度不可变。Java中String 是immutable（不可变）的。
            // 用于存放字符的数组被声明为final的，因此只能赋值一次，不可再更改。
            // ! 常量池

            // StringBuffer：字符串变量（Synchronized，即线程安全）。如果要频繁对字符串内容进行修改，
            // 出于效率考虑最好使用 StringBuffer，如果想转成 String 类型，可以调用 StringBuffer 的 toString() 方法。
            // Java.lang.StringBuffer 线程安全的可变字符序列。在任意时间点上它都包含某种特定的字符序列，
            // 但通过某些方法调用可以改变该序列的长度和内容。可将字符串缓冲区安全地用于多个线程。

            // StringBuilder：字符串变量（非线程安全）。在内部 StringBuilder 对象被当作是一个包含字符序列的变长数组。

            // 基本原则：

            // 操作少量的数据 String
            // 单线程操作大量数据 StringBuilder
            // 多线程操作大量数据 StringBuffer

            // String 长度大小不可变
            // StringBuffer 和 StringBuilder 长度可变
            // StringBuffer 线程安全 StringBuilder 线程不安全
            // StringBuilder 速度快

            // stringbuffer 基本没有适用场景，你应该在所有的情况下选择使用 stringbuiler，除非你真的遇到了一个需要线程安全的场景
            //
            // 单行用加号拼接字符串是没有性能损失的，java 编译器会隐式的替换成 stringbuilder，
            // 但在有循环的情况下，编译器没法做到足够智能的替换，仍然会有不必要的性能损耗，
            // 因此，用循环拼接字符串的时候，还是老老实实的用 stringbuilder 吧。
        }

        if (x) // 宣告變數 内置数据类型 可变参数 包装类型
        {
            // ! https://www.runoob.com/java/java-basic-datatypes.html
            // 留言區 数据类型转换的补充

            if (x) // 強轉型
            {
                double var_1 = 5.5;
                int var_2    = (int) var_1; // ! Res : 5
            }

            if (x) // 宣告變數 内置数据类型
            {
                // * -128 ~ 127 有整數池

                char str1 = 'A';
                // 最小值是 \u0000（即为0）
                // 最大值是 \uffff（即为65,535）
                //
                // char类型是一个单一的 16 位 Unicode 字符
                // char 数据类型可以储存任何字符

                // 字符串常量和字符常量都可以包含任何Unicode字符。例如：
                char str2   = '\u0001';
                String str3 = "\u0001";

                byte var1;  // == int * 1/4 | // == char | // 最小值是 -128（-2^7）// 最大值是 127（2^7-1）
                short var2; // == int * 1/2 | // 最小值是 -32768（-2^15）// 最大值是 32767（2^15 - 1）

                long var4;
                // 最小值是 -9,223,372,036,854,775,808（-2^63）
                // 最大值是 9,223,372,036,854,775,807（2^63 -1）
                //
                // 这种类型主要使用在需要比较大整数的系统上
                // 默认值是 0L
                // "L"理论上不分大小写，但是若写成"l"容易与数字"1"混淆，不容易分辩。所以最好大写。
            }

            if (x) // 宣告變數 可变参数 传入不定长度的参数 基于数组
            {
                // ! https://www.runoob.com/java/java-methods.html
                // ! https://www.runoob.com/w3cnote/java-varargs-parameter.html

                // 在方法声明中，在指定参数类型后加一个省略号(...)
                // 一个方法中只能指定一个可变参数，必须是方法的最后一个参数，但其前面可以有也可以没有任何其他参数。
                // 任何普通的参数必须在它之前声明。
                // Java的可变参数，会被编译器转型为一个数组
                // 变长参数在编译为字节码后，在方法签名中就是以数组形态出现的。这两个方法的签名是一致的，
                // 不能作为方法的重载。如果同时出现，是不能编译通过的。可变参数可以兼容数组，反之则不成立

                public class Test2 {
                    public void printMax(double... numbers) {
                        System.out.println("test");
                    }
                }

                public class Test2 {
                    public void foo(String... varargs) {
                        System.out.println("test");
                    }

                    public static void main(String[] args) {
                        foo("arg1", "arg2", "arg3");
                        // or
                        foo(new String[] { "arg1", "arg2", "arg3" });
                    }
                }
            }

            if (x) // 包装类型
            {
                if (x) // 包装类型 基礎
                {
                    // ! Number & Math 类方法
                    // https://www.runoob.com/java/java-number.html

                    // ! Character 方法
                    // http://www.runoob.com/java/java-character.html

                    // ! java.lang.Character API
                    // http://www.runoob.com/manual/jdk1.6/java/lang/Character.html

                    // ! String 方法
                    // http://www.runoob.com/java/java-string.html

                    // ! StringBuffer 方法
                    // http://www.runoob.com/java/java-stringbuffer.html

                    // ! Java String API
                    // http://www.runoob.com/manual/jdk1.6/java/lang/String.html

                    // 1.集合不允许存放基本类型数据，只能存放引用类型数据，比如包装类型。以List为例,
                    // 大家都知道一个动态数组的 add(Object o) 方法只能接受一个引用类型。

                    // 2.基本类型和包装类之间可以相互转换，又叫自动装箱与自动拆箱。
                    // 这个特性让我们在编码的时候能够更注重于业务的开发，而不是每转换一次就需要写一堆转换代码。

                    // 3.通过包装类型可以实现 8 种基本数据类型 + String 类型 之间可以相互转换
                    int num = Integer.parseInt("1");

                    // 4.有时候一个函数需要传递一个Object变量 而你想传递int类型的进去显然不行，这就要用到包装类。
                    // 如下代码：想传递5进去就可以这样
                    // ! e.g. ^^^^^
                    // public void Test1(int var1) {}
                    // Test1(new Integer(5));
                }

                if (x) // 包装类型 Character
                {
                    isLetter();     // 是一个字母
                    isDigit();      // 是一个数字字符
                    isWhitespace(); // 是一个空白字符
                    isUpperCase();  // 是大写字母
                    isLowerCase();  // 是小写字母
                    toUpperCase();  // 字母的大写形式
                    toLowerCase();  // 字母的小写形式
                    toString();     // 返回字符的字符串形式，字符串的长度仅为1
                }

                if (x) // 包装类型 String
                {
                    // 根据 jdk 的源码来分析。
                    // 字符串实际上就是一个 char 数组，并且内部就是封装了一个 char 数组。
                    // 并且这里 char 数组是被 final 修饰的
                    // 并且 String 中的所有的方法，都是对于 char 数组的改变，只要是对它的改变，方法内部都是返回一个新的 String 实例。

                    public final class String implements java.io.Serializable, Comparable<String>, CharSequence {
                        /** The value is used for character storage. */
                        private final char value[];
                    }

                    String str_1 = "str_1";

                    str_1.length();      // 字串長度
                    str_1.concat(str_2); // 字串連接, 通常用 '+'
                    // or
                    "str_1".concat(str_1);
                    str_1.format("%d", var_1); // 字串初始化

                    // * ^^^^^
                    System.out.println(String.format("%1$9d", -31));     // -31
                    System.out.println(String.format("%1$,09d", -3123)); // -0003,123

                    // '-' 在最小宽度内左对齐，不可以与"用0填充"同时使用
                    // '#' 只适用于8进制和16进制，8进制时在结果前面增加一个0，16进制时在结果前面增加0x
                    // '+' 结果总是包括一个符号(一般情况下只适用于10进制，若对象为BigInteger才可以用于8进制和16进制)
                    // ' ' 正值前加空格，负值前加负号(一般情况下只适用于10进制，若对象为BigInteger才可以用于8进制和16进制)
                    // '0' 结果将用零来填充
                    // ',' 只适用于10进制，每3位数字之间用"，"分隔
                    // '(' 若参数是负数，则结果中不添加负号而是用圆括号把数字括起来(同'+'具有同样的限制)
                    //
                    // 转换方式：
                    // d-十进制 o-八进制 x或X-十六进制
                }

                if (x) // 包装类型 StringBuffer
                {
                    // ! StringBuffer 方法
                    // http://www.runoob.com/java/java-stringbuffer.html

                    // public StringBuffer append(String str); // 将指定的字符串追加到此字符序列。
                    // public StringBuffer reverse(); // 将此字符序列用其反转形式取代。
                    // public delete(int start, int end); // 移除此序列的子字符串中的字符。
                    // public insert(int offset, int i); // 将 int 参数的字符串表示形式插入此序列中。
                    // replace(int start, int end, String str); // 使用给定 String 中的字符替换此序列的子字符串中的字符。
                }

                if (x) // 包装类型 Arrays
                {
                    // ! Arrays 方法
                    // http://www.runoob.com/java/java-array.html

                    int[] arr_1 = { 10, 20, 30, 40, 50 };                 // 陣列 擴容
                    arr_1       = Arrays.copyOf(arr_1, arr_1.length + 1); // ! res : 10 20 30 40 50 0
                }
            }

            if (x) // 包装类 求大小
            {
                System.out.println("基本类型 : int 二进制位数 = " + Integer.SIZE);
                System.out.println("包装类   : java.lang.Integer");
                System.out.println("最小值   : Integer.MIN_VALUE = " + Integer.MIN_VALUE);
                System.out.println("最大值   : Integer.MAX_VALUE = " + Integer.MAX_VALUE);
            }

            if (x) // parse
            {
                String s = "1";
                byte b   = Byte.parseByte(s);
                short t  = Short.parseShort(s);
                int i    = Integer.parseInt(s);
                long l   = Long.parseLong(s);
                Float f  = Float.parseFloat(s);
                Double d = Double.parseDouble(s);
            }
        }

        if (x) // 數組 | 陣列 | 数组
        {
            if (x) // 陣列 基礎
            {
                int[] arr_1 = new int[ 100 ]; // Java (推薦)
                int arr_2[] = new int[ 100 ]; // CPP 風格 (不推薦)
                int arr_3[] = { 0, 1, 2, 3 };

                // int arg1[], [] arg2; // ! Error
                // int arg1[], arg2[];
                int[] arg1, arg2;
                arg2      = new int[ 10 ];
                arg2[ 0 ] = 1;
                System.out.println(arg2[ 0 ]); // ! res : 1

                // ! vvvvv e.g. 数组作为函数的参数 vvvvv

                class printArray {

                    public static void printArray(int[] arr) {
                        for (int i = 0; i < array.length; i++) {
                            System.out.print(array[ i ] + " ");
                        }
                    }

                    /**
                     * @param args
                     */
                    public static void main(String[] args) {

                        int[] result = new int[] { 3, 1, 2, 6, 4, 2 };
                        printArray(result);
                        printArray(new int[] { 3, 1, 2, 6, 4, 2 });
                    }
                }

                // ! ^^^^^ e.g. 数组作为函数的参数 ^^^^^

                // ! ^^^^^ e.g. 数组作为函数的返回值 ^^^^^
                class Reverse {

                    public static int[] reverse(int[] list) {

                        int result[] = new int[ list.length ];

                        for (int i = 0, j = result.length - 1; i < list.length; i++, j--) {
                            result[ j ] = list[ i ];
                        }

                        return result;
                    }
                }
                // !^| e.g. 数组作为函数的返回值 ^^^^^
            }

            if (x) // 多维数组
            {
                String str[][] = new String[ 3 ][ 4 ];
            }
        }

        if (x) // length, length(), size
        {
            System.out.println(arr.length);
            System.out.println(str.length());
            System.out.println(Set.size());
        }

        if (x) // 位运算符
        {
            int var1 = 1111;
            int var2 = var1 >>> 2; // == 0000 1111
            // >>> == >> + 移动得到的空位以零填充
        }

        if (x) // 進制
        {
            // byte、int、long、和short 都可以用十进制、16进制以及8进制的方式来表示。

            int decimal = 100;
            int octal   = 0144; // 0 == 8 进制
            int hexa    = 0x64; // 0x == 16 进制
        }

        if (x) // instanceof | 检查特定类型
        {
            // 该运算符用于操作对象实例，检查该对象是否是一个特定类型（类类型或接口类型）。

            String str  = "James";
            boolean res = str instanceof String; // 由于 name 是 String 类型，所以返回真
        }

        if (x) // 修饰符
        {
            // ! https://www.runoob.com/java/java-modifier-types.html#protected-desc

            if (x) // static
            {
                // static String str_1;
                // static{
                // str_1 = "123";
                // }
            }

            if (x) // final 常量
            {
                final int var_1; // == const
            }

            if (x) // transient
            {
                // 序列化的对象包含被 transient 修饰的实例变量时，java 虚拟机(JVM)跳过该特定的变量。
                // 该修饰符包含在定义变量的语句中，用来预处理类和变量的数据类型。
                public transient int var1 = 55; // 不会持久化
                public int var2;                // 持久化
            }

            if (x) // volatile
            {
                // volatile 修饰的成员变量在每次被线程访问时，都强制从共享内存中重新读取该成员变量的值。
                // 而且，当成员变量发生变化时，会强制线程将变化值回写到共享内存。这样在任何时刻，
                // 两个不同的线程总是看到某个成员变量的同一个值。
                //
                // 一个 volatile 对象引用可能是 null。

                // ! ^^^^^ e.g. volatile ^^^^^
                public class MyRunnable implements Runnable {
                    private volatile boolean active;

                    public void run() {
                        active = true;

                        while (active) { // 第一行
                        }
                    }

                    public void stop() {
                        active = false; // 第二行
                    }
                }
                // 通常情况下，在一个线程调用 run() 方法（在 Runnable 开启的线程），在另一个线程调用 stop() 方法。
                // 如果 第一行 中缓冲区的 active 值被使用，那么在 第二行 的 active 值为 false 时循环不会停止。
                //
                // 但是以上代码中我们使用了 volatile 修饰 active，所以该循环会停止。
                // !^| e.g. volatile ^^^^^
            }
        }

        if (x) { // 強轉型 自動轉型

            // java 中，如果比int类型小的类型做运算，java在编译的时候就会将它们统一强转成int类型。
            // 当比int类型大的类型做运算，就会自动转换成它们中最大类型那个。

            if (x) { // 強轉型

                int var2 = (int) var1;

                // 浮点数到整数的转换是通过舍弃小数得到，而不是四舍五入
                int var3 = (int) 23.7;    // == 23
                int var4 = (int) -45.89f; // == -45
            }

            if (x) { // 自動轉型

                char str1 = 'A';
                int var1  = str1; // ASCII A == 65
            }
        }

        if (x) // 引用类型
        {
            Test1 Test1 = new Test1("Test1");

            // 在Java中，引用类型的变量非常类似于C/C++的指针。引用类型指向一个对象，指向对象的变量是引用变量。
            // 变量一旦声明后，类型就不能被改变了。
            //
            // 对象、数组都是引用数据类型。
            // 所有引用类型的默认值都是null。
            // 一个引用变量可以用来引用任何与之兼容的类型。
        }

        if (x) // 增强(each) for 迴圈
        {
            // ! ^^^^^ e.g. 增強 for 迴圈 ^^^^^
            public class Test {

                public static void main(String args[]) {

                    int[] arr_1 = { 10, 20, 30, 40, 50 };
                    for (int i : arr_1) {
                        System.out.print(i);
                        System.out.print(",");
                    }

                    System.out.print("\n");

                    String[] arr_2 = { "James", "Larry", "Tom", "Lacy" };
                    for (String i : arr_2) {
                        System.out.print(i);
                        System.out.print(",");
                    }
                }
            }
            // !^| e.g. 增強 for 迴圈 ^^^^^
        }

        if (x) // switch
        {
            // 如果 case 语句块中没有 break 语句时，JVM 并不会顺序输出每一个 case 对应的返回值，
            // 而是继续匹配，匹配不成功则返回默认 case。
            //
            // 如果 case 语句块中没有 break 语句时，匹配成功后，从当前 case 开始，后续所有 case 的值都会输出。

            public class Test {
                public static void main(String args[]) {

                    int control = 2;
                    switch (control) {

                        case 1:
                            System.out.println("1");

                        case 2:
                            System.out.println("2");

                        case 3:
                            System.out.println("3");
                            break;

                        default:
                            System.out.println("0");
                    }

                    // ! res : 2, 3
                }
            }
        }

        if (x) // 正则表达式
        {
            // .（点号）也是一个正则表达式，它匹配任何一个字符如："a" 或 "1"。

            // ^\d+(\.\d+)?

            // ^ 定义了以什么开始
            // \s+ 匹配多个空格
            // \d+ 匹配一个或多个数字
            // ? 设置括号内的选项是可选的
            // \. 匹配 "."

            // 可以匹配的实例："5", "1.5" 和 "2.21"
        }

        if (x) // Java 日期时间
        {
            // ! Java 日期时间
            // http://www.runoob.com/java/java-date-time.html

            if (x) // 日期时间
            {
                // ! ^^^^^ e.g. 日期时间 ^^^^^

                // import java.util.Date;

                public class DateDemo {
                    public static void main(String args[]) {

                        Date date = new Date();              // 初始化 Date 对象
                        System.out.println(date.toString()); // 使用 toString() 函数显示日期时间
                    }
                }
                // ! res : Fri Apr 05 02:59:25 UTC 2019

                // !^| e.g. 日期时间 ^^^^^
            }

            if (x) // 日期比较
            {
                // Java使用以下三种方法来比较两个日期：

                // 使用 getTime() 方法获取两个日期（自1970年1月1日经历的毫秒数值），然后比较这两个值。
                // 使用方法 before()，after() 和 equals()。例如，一个月的12号比18号早，
                // 则 new Date(99, 2, 12).before(new Date (99, 2, 18)) 返回true。
                // 使用 compareTo() 方法，它是由 Comparable 接口定义的，Date 类实现了这个接口。
            }

            if (x) // 日期和时间的格式化编码
            {
                // http://www.runoob.com/java/java-date-time.html

                SimpleDateFormat ft = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");

                // G // 纪元标记 // AD
                // y // 四位年份 // 2001
                // M // 月份 // July or 07
                // d // 一个月的日期 // 10
                // h // A.M./P.M. (1~12)格式小时 // 12
                // H // 一天中的小时 (0~23) // 22
                // m // 分钟数 // 30
                // s // 秒数 // 55
                // S // 毫秒数 // 234
                // E // 星期几 // Tuesday
                // D // 一年中的日子 // 360
                // F // 一个月中第几周的周几 // 2 (second Wed. in July)
                // w // 一年中第几周 // 40
                // W // 一个月中第几周 // 1
                // a // A.M./P.M. 标记 // PM
                // k // 一天中的小时(1~24) // 24
                // K // A.M./P.M. (0~11)格式小时 // 10
                // z // 时区 // Eastern Standard Time
                // ' // 文字定界符 // Delimiter
                // " // 单引号 // `
            }

            if (x) // 使用printf格式化日期
            {
                // http://www.runoob.com/java/java-date-time.html

                // ! Java 格式化输出 printf 例子
                // http://www.runoob.com/w3cnote/java-printf-formate-demo.html

                // printf 方法可以很轻松地格式化时间和日期。使用两个字母格式，它以 %t 开头并且以下面表格中的一个字母结尾。

                // c // 包括全部日期和时间信息 // 星期六 十月 27 14:21:20 CST 2007
                // F // 年-月-日"格式 // 2007/10/27
                // D // 月/日/年"格式 // 10/27/07
                // r // HH:MM:SS PM"格式（12时制） // 2:25:51 PM
                // T // HH:MM:SS"格式（24时制） // 14:28:16
                // R // HH:MM"格式（24时制） // 14:28

                // ! ^^^^^ e.g. ^^^^^

                Date date = new Date();
                System.out.printf("全部日期和时间信息：%tc%n", date); // c的使用
                System.out.printf("年-月-日格式：%tF%n", date);       // f的使用

                // * ^^^^^

                // 如果需要重复提供日期，可以利用一个格式化字符串指出要被格式化的参数的索引。
                // 索引必须紧跟在%后面，而且必须以$结束。例如：

                System.out.printf("%1$s %2$tB %2$td, %2$tY", "Due date:", date); // 使用toString()显示日期和时间
                // ! res : Due date: February 09, 2014

                // * ^^^^^

                // 使用 < 标志。它表明先前被格式化的参数要被再次使用。例如：

                System.out.printf("%s %tB %<te, %<tY", "Due date:", date); // 显示格式化时间
                // ! res : Due date: February 09, 2014

                // !^| e.g. ^^^^^
            }

            if (x) // 包装类型 Calendar | GregorianCalendar
            {
                // import java.util.Calendar;

                // ! Calendar
                // ! GregorianCalendar
                // http://www.runoob.com/java/java-date-time.html
            }
        }

        if (x) // Java 异常处理 | 異常
        {
            // ! https://www.runoob.com/java/java-exceptions.html

            // 检查性异常: 不处理编译不能通过
            // 非检查性异常:不处理编译可以通过，如果有抛出直接抛到控制台
            // 运行时异常: 就是非检查性异常
            // 非运行时异常: 就是检查性异常

            // * Java 语言定义了一些异常类在 java.lang 标准包中。
            // * 标准运行时异常类的子类是最常见的异常类。由于 java.lang 包是默认加载到所有的 Java 程序的，
            // * 所以大部分从运行时异常类继承而来的异常都可以直接使用。

            // 检查性异常：最具代表的检查性异常是用户错误或问题引起的异常，这是程序员无法预见的。
            // 例如要打开一个不存在文件时，一个异常就发生了，这些异常在编译时不能被简单地忽略。
            //
            // 运行时异常： 运行时异常是可能被程序员避免的异常。与检查性异常相反，运行时异常可以在编译时被忽略。
            //
            // 错误： 错误不是异常，而是脱离程序员控制的问题。错误在代码中通常被忽略。
            // 例如，当栈溢出时，一个错误就发生了，它们在编译也检查不到的。

            // ! vvvvv e.g. vvvvv

            public class TestException {

                /**
                 * @param args
                 */
                public static void main(String args[]) {

                    try {
                        int a[] = new int[ 2 ];
                        System.out.println("Access element three :" + a[ 3 ]);
                    } catch (ArrayIndexOutOfBoundsException e) {
                        System.out.println("Exception thrown  :" + e);
                    }

                    System.out.println("Out of the block");
                }

                // ! res :
                // Exception thrown :java.lang.ArrayIndexOutOfBoundsException: 3
                // Out of the block
            }

            // ! ^^^^^ e.g. ^^^^^

            if (x) // 捕获异常
            {
                // try/catch 代码块中的代码称为保护代码

                try { // try == if
                    code();
                } catch (

                    ExceptionName e1) { // catch == else if
                    code();
                } catch (ExceptionName e1) { // catch == else if
                    code();
                } finally { // 必定執行
                    code();
                }
            }

            if (x) // catch finally 優先級
            {
                // * finally不一定被执行，，例如 catch 块中有退出系统的语句 System.exit(-1); finally就不会被执行
                // * 先执行catch里面的代码后执行finally里面的代码最后才return1

                try {
                    code();
                } catch (Exception e) {
                    System.out.println("catch is begin");
                    return 1;
                } finally {
                    System.out.println("finally is begin");
                }
                // ! res :
                // 在catch里面有一个return，那么finally会不会被执行呢？答案是肯定的，上面代码的执行结果为：
                // * catch is begin
                // * finally is begin
                // 也就是说会先执行catch里面的代码后执行finally里面的代码最后才return1

                // * ^^^^^

                try {
                    code();
                } catch (Exception e) {
                    System.out.println("catch is begin");
                    return 1;
                } finally {
                    System.out.println("finally is begin");
                    return 2;
                }
                // ! res :
                // 在b代码中输出结果跟a是一样的，然而返回的是return 2
                // 原因很明显，就是执行了finally后已经return了，所以catch里面的return不会被执行到。
                // 也就是说finally永远都会在catch的return前被执行。（这个是面试经常问到的问题哦！）
            }

            if (x) // 非检查性异常
            {
                // ArithmeticException // * 当出现异常的运算条件时，抛出此异常。例如，一个整数"除以零"时，抛出此类的一个实例。
                // ArrayIndexOutOfBoundsException
                // * 用非法索引访问数组时抛出的异常。如果索引为负或大于等于数组大小，则该索引为非法索引。
                // ArrayStoreException // * 试图将错误类型的对象存储到一个对象数组时抛出的异常。
                // ClassCastException // * 当试图将对象强制转换为不是实例的子类时，抛出该异常。
                // IllegalArgumentException // * 抛出的异常表明向方法传递了一个不合法或不正确的参数。

                // IllegalMonitorStateException
                // * 抛出的异常表明某一线程已经试图等待对象的监视器，或者试图通知其他正在等待对象的监视器而本身没有指定监视器的线程。

                // IllegalStateException
                // * 在非法或不适当的时间调用方法时产生的信号。换句话说，即 Java 环境或 Java 应用程序没有处于请求操作所要求的适当状态下。

                // IllegalThreadStateException // * 线程没有处于请求操作所要求的适当状态时抛出的异常。
                // IndexOutOfBoundsException // * 指示某排序索引（例如对数组、字符串或向量的排序）超出范围时抛出。
                // NegativeArraySizeException // * 如果应用程序试图创建大小为负的数组，则抛出该异常。
                // NullPointerException // * 当应用程序试图在需要对象的地方使用 null 时，抛出该异常
                // NumberFormatException // * 当应用程序试图将字符串转换成一种数值类型，但该字符串不能转换为适当格式时，抛出该异常。
                // SecurityException // * 由安全管理器抛出的异常，指示存在安全侵犯。
                // StringIndexOutOfBoundsException // * 此异常由 String 方法抛出，指示索引或者为负，或者超出字符串的大小。
                // UnsupportedOperationException // * 当不支持请求的操作时，抛出该异常。
            }

            if (x) // 检查性异常
            {
                // ClassNotFoundException // * 应用程序试图加载类时，找不到相应的类，抛出该异常。
                // CloneNotSupportedException
                // * 当调用 Object 类中的 clone 方法克隆对象，但该对象的类无法实现 Cloneable 接口时抛出该异常。

                // IllegalAccessException // * 拒绝访问一个类的时候，抛出该异常。

                // InstantiationException // * 当试图使用 Class 类中的 newInstance 方法创建一个类的实例，
                // * 而指定的类对象因为是一个接口或是一个抽象类而无法实例化时，抛出该异常。

                // InterruptedException // * 一个线程被另一个线程中断，抛出该异常。
                // NoSuchFieldException // * 请求的变量不存在
                // NoSuchMethodException // * 请求的方法不存在
            }

            if (x) // 异常方法
            {
                // public String getMessage() // * 返回关于发生的异常的详细信息。这个消息在Throwable 类的构造函数中初始化了。
                // public Throwable getCause() // * 返回一个Throwable 对象代表异常原因。
                // public String toString() // * 使用getMessage()的结果返回类的串级名字。
                // public void printStackTrace() // * 打印toString()结果和栈层次到System.err，即错误输出流。
                // public StackTraceElement [] getStackTrace()
                // * 返回一个包含堆栈层次的数组。下标为0的元素代表栈顶，最后一个元素代表方法调用堆栈的栈底。
                // public Throwable fillInStackTrace()
                // * 用当前的调用栈层次填充Throwable 对象栈层次，添加到栈层次任何先前信息中。
            }

            if (x) // throws/throwx
            {
                // 如果一个方法没有捕获到一个检查性异常，那么该方法必须使用 throws 关键字来声明。throws 关键字放在方法签名的尾部。
                // 也可以使用 throw 关键字抛出一个异常，无论它是新实例化的还是刚捕获到的。

                // ! ^^^^^ e.g. RemoteException 异常 ^^^^^
                // import java.io.*;

                public class className {
                    // 單個異常
                    public void deposit(double amount) throws RemoteException {
                        throw new RemoteException();
                    }

                    // 多個異常
                    public void withdraw(double amount) throws RemoteException, InsufficientFundsException {
                        throw new RemoteException();
                    }
                }
                // !^| e.g. RemoteException 异常 ^^^^^

                if (x) // ! e.g. 異常 - 負數 ^^^^^
                {
                    // ! ^^^^^ e.g. 異常 - 負數 ^^^^^
                    // import java.io.*;

                    // 異常 - 負數
                    class NegativeException extends Exception {

                        protected NegativeException(String msg, int var1) {
                            super(msg); // 调用父类有参构造,获得异常信息
                            this.var1_ = var1;
                        }

                        public int getValue() {
                            return var1_;
                        }

                        private int var1_;
                    }

                    class Calculation {

                        int Div(int var1, int var2) throws NegativeException {
                            if (var2 < 0) {
                                throw new NegativeException("異常 - 除數為負數 : ", var2); // 手动通过throw关键字抛出一个自定义异常对象
                            }
                            return (var1 / var2);
                        }
                    }

                    public class Test4 {
                        public static void main(String[] args) {

                            Calculation Calc = new Calculation();

                            try {
                                int x = Calc.Div(4, -9);
                                System.out.println("x=" + x);
                            } catch (NegativeException e) {
                                System.out.println(e.toString());
                                System.out.println("錯誤的負數是：" + e.getValue());
                            } catch (Exception e) {
                                // 大的异常放在下方, 小的异常放在上方
                                System.out.println(e.getMessage());
                            }

                            System.out.println("end");
                        }
                    }
                    // !^| e.g. 異常 - 負數 ^^^^^
                }
            }

            if (x) // 声明自定义异常
            {
                // Java 中可以自定义异常。编写自己的异常类时需要记住下面的几点。
                // 所有异常都必须是 Throwable 的子类。
                // 如果希望写一个检查性异常类，则需要继承 Exception 类。
                // 如果你想写一个运行时异常类，那么需要继承 RuntimeException 类。

                class MyException extends Exception {
                }

                class MyException extends RuntimeException {
                }

                if (x) // ! e.g. 声明自定义异常 ^^^^^
                {
                    // ! ^^^^^ e.g. 声明自定义异常 ^^^^^
                    // * 以下实例是一个银行账户的模拟，通过银行卡的号码完成识别，可以进行存钱和取钱的操作。

                    // import java.io.*;

                    // 自定义异常类，继承Exception类
                    public class InsufficientFundsException extends Exception {
                        public InsufficientFundsException(double amount) {
                            this.amount = amount;
                        }

                        public double getAmount() {
                            return amount;
                        }

                        private double amount; // 此处的amount用来储存当出现异常（取出钱多于余额时）所缺乏的钱
                    }

                    // * ^^^^^

                    // import java.io.*;

                    // * 此类模拟银行账户
                    public class CheckingAccount {

                        public CheckingAccount(int number) {
                            this.number = number;
                        }

                        // 存钱
                        public void deposit(double amount) {
                            balance += amount;
                        }

                        // 取钱
                        public void withdraw(double amount) throws InsufficientFundsException {
                            if (amount <= balance) {
                                balance -= amount;
                            } else {
                                double needs = amount - balance;
                                throw new InsufficientFundsException(needs);
                            }
                        }

                        // 返回余额
                        public double getBalance() {
                            return balance;
                        }

                        // 返回卡号
                        public int getNumber() {
                            return number;
                        }

                        // balance为余额，number为卡号
                        private double balance;
                        private int number;
                    }

                    // * ^^^^^

                    public class BankDemo {
                        public static void main(String[] args) {

                            System.out.println("Depositing $500...");

                            CheckingAccount c = new CheckingAccount(101);
                            c.deposit(500.00);

                            try {
                                System.out.println("\nWithdrawing $100...");
                                c.withdraw(100.00);
                                System.out.println("\nWithdrawing $600...");
                                c.withdraw(600.00);
                            } catch (InsufficientFundsException e) {
                                System.out.println("Sorry, but you are short $" + e.getAmount());
                                e.printStackTrace();
                            }
                        }
                    }
                    // ! res :
                    // * Depositing $500...
                    // *
                    // * Withdrawing $100...
                    // *
                    // * Withdrawing $600...
                    // * Sorry, but you are short $200.0
                    // * InsufficientFundsException
                    // * at CheckingAccount.withdraw(CheckingAccount.java:25)
                    // * at BankDemo.main(BankDemo.java:13)

                    // !^| e.g. 声明自定义异常 ^^^^^
                }
            }

            if (x) // 通用异常
            {
                // 在Java中定义了两种类型的异常和错误。
                //
                // JVM(Java虚拟机) 异常：由 JVM 抛出的异常或错误。
                // 例如：NullPointerException，ArrayIndexOutOfBoundsException，ClassCastException
                //
                // 程序级异常：由程序或者API程序抛出的异常。例如 IllegalArgumentException 类，IllegalStateException 类。
            }
        }

        if (x) // ! 未整理
        {
            // JAVA的引用变量实际就是一个指针值...就是一个指针变量.
            // C语言里说指针值是一个十六进制的值,但JAVA把它隐藏了,你无法得到这个值.
            // 但是它可以保存在变量中,相同变量之间可以相互交换值.

            Color c = new Color(r, g, b);
            Color d;
            c = d; // c 的值实际就是一个指针值,JVM会根据这个值去找到对象的地址.
        }
    }
}