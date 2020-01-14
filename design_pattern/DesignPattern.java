// ******************************
// *
// * date     : 2019/11/10
// *
// * author   : 施冠年
// * mail     : Co6901251@gmail.com
// *
// * function :
// *
// * Design Pattern
// *
// * 設計模式
// *
// ******************************

public class DesignPattern {

    public static void main(String[] args) {

        int design_pattern = 1;

        if (design_pattern) // 簡單工廠方法(Simple Factory Method Pattern) & 工廠方法(Factory Method Pattern)
        {

            // ******************************
            // *
            // * 用途     : 用於類型相似，且方法相似(Overriding, 向上轉型)
            // *
            // * 簡單工廠方法(Simple Factory Method Pattern) : 新增品項 -> 修改工廠(判斷式)
            // * 工廠方法　　(       Factory Method Pattern) : 新增品項 -> 新增工廠(類)
            // *
            // * 簡單工廠方法違反 Open-Closed Principle(OCP),
            // * OCP : 不修改既有程式碼的情況下，容易擴充程式功能
            // *
            // ******************************

            BlackTea blackTea = new Factory("BlackTea"); // 簡單工廠方法
            BlackTea blackTea = new BlackTeaFactory();   // 工廠方法
        }

        if (design_pattern) // 策略模式(Strategy Pattern)
        {

            // 不同情況，不同策略 // ! 有點像接口

            車 汽車 = new 車(new 輪子());
            車 戰車 = new 車(new 履帶());
        }

        if (design_pattern) { // 單例模式(Singleton Pattern)

            // 存取 IO 和資料庫等資源，考慮使用單例模式

            // 有幾種方式可以實現單例模式 :
            //
            // 懶散(Lazy)模式（線程不安全）
            // 懶散模式（線程安全）
            // 積極模式
            // 雙重鎖 (Double ChockLock)
            // 登記式（靜態內部類）
            // 枚舉 (enumeration)
        }
    }
}