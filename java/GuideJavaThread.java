// ******************************
// *
// * Author   : 施冠年
// * Date     : 2019/10/11
// * Mail     : Co6901251@gmail.com
// *
// * Function :
// *
// * Java notes : Thread
// *
// * Java 筆記 : 多線程
// *
// ******************************

public class JavaGuideThread {

    public JavaGuideThread() {

        int java_guide_thread = 1;

        // * public interface Runnable {}
        // * class Thread implements Runnable {}

        if (java_guide_thread) // 創建線程
        {
            // Java 提供了三种创建线程的方法：

            // 通过实现 Runnable 接口；
            // 通过继承 Thread 类本身；
            // 通过 Callable 和 Future 创建线程。

            // * -----

            // 通过实现 Runnable 接口来创建线程
            // 创建一个线程，最简单的方法是创建一个实现 Runnable 接口的类。

            // 为了实现 Runnable，一个类只需要执行一个方法调用 run()
            // * public void run(){}

            // 你可以重写该方法，重要的是理解的 run() 可以调用其他方法，使用其他类，并声明变量，就像主线程一样。

            // 在创建一个实现 Runnable 接口的类之后，你可以在类中实例化一个线程对象。

            // Thread 定义了几个构造方法，下面的这个是我们经常使用的：

            // Thread(Runnable threadOb,String threadName);
            // 这里，threadOb 是一个实现 Runnable 接口的类的实例，并且 threadName 指定新线程的名字。

            // 新线程创建之后，你调用它的 start() 方法它才会运行。

            // * void start();

            // start()
            // start()不能被重复调用
            // 启动一个新线程，用start方法来启动线程，真正实现了多线程运行，
            //
            // 通过start()方法来启动的新线程，处于就绪（可运行）状态，并没有运行，
            // 一旦得到cpu时间片，就开始执行相应线程的run()方法，这里方法run()称为线程体，
            // 它包含了要执行的这个线程的内容，run方法运行结束，此线程随即终止。
            //
            // 即无需等待某个线程的run方法体代码执行完毕就直接继续执行下面的代码。
            // 这里无需等待run方法执行完毕，即可继续执行下面的代码，即进行了线程切换。

            // run()
            // run()就和普通的成员方法一样，可以被重复调用。
            // 如果直接调用run方法，并不会启动新线程
            //
            // 程序中依然只有主线程这一个线程，其程序执行路径还是只有一条，还是要顺序执行，
            // 还是要等待run方法体执行完毕后才可继续执行下面的代码，这样就没有达到多线程的目的。

            // 总结：调用start方法方可启动线程，而run方法只是thread的一个普通方法调用，还是在主线程里执行。
        }

        if (java_guide_thread) // 並發 & 並行
        {
            // 並發計算(並行計算)(Concurrent computing) : 一個 CPU, 时间划分, 輪流執行
            // 並行計算(平行計算)(Parallel   computing) : 多個 CPU, 　　　　  同時執行
        }

        if (java_guide_thread) // 三大性质
        {
            // 三大性质 :
            // 原子性
            // 有序性
            // 可见性

            // volatile     // 可見性, 可以保证一定的有序性
            // synchronized // 有序性, 原子性, 可见性
            // Lock         // 原子性, 可见性

            // 原子性 : 操作不可中断, 全部执行成功 or 全部执行失败
            // 在多个线程一起执行时，一个操作一旦开始，就不会被其他线程所干扰。
            //
            // 运算结果并不依赖于变量的当前值，或者能够确保只有一个线程修改变量的值；
            // 变量不需要与其他的状态变量共同参与不变约束

            // 基本数据类型的变量和赋值操作才是原子性的（注：在 32 位的 JDK 环境下，对 64 位数据的读取不是原子性操作 *，如 long、double）。
            // 要想在多线程环境下保证原子性，则可以通过锁、synchronized 来确保。
        }

        if (java_guide_thread) // volatile
        {
            // 在寫入一個 volatile 變量時，強制它寫入到內存中
            // 在讀取一個 volatile 變量時，強制它從內存中重新讀取
            // 保證可見性
        }

        if (java_guide_thread) // synchronized
        {
            // synchronized 有兩種加鎖方式，
            // 一種是對類加鎖，所有線程調用都需先獲取類的鎖，沒鎖就堵塞；
            // 一種是對象加鎖，多線程相同對象的方法調用才會等待獲取對象鎖
        }

        if (java_guide_thread) //
        {
        }

        if (java_guide_thread) //
        {
        }
    }
}