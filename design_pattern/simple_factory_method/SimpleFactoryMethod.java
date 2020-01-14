// package java_guide_design_pattern;

// ******************************
// *
// * author   : 施冠年
// * date     : 2019/11/14
// * mail     : Co6901251@gmail.com
// *
// * function : 簡單工廠方法(Simple Factory Method Pattern)
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

public class SimpleFactoryMethod {

    /**
    * @param args
    */
    public static void main(String[] args) {
        DrinksFactory drinksFactory = new DrinksFactory();
        BlackTea blackTea           = (BlackTea) drinksFactory.CreateDrinks("BlackTea");
        blackTea.AddSugar(); // ! res : AddSugar
    }
}

// * 飲料

public interface Drinks {
    default void
        AddSugar() {
            System.out.println("Add sugar");
        }
}

// 以下有 20 種飲料...
public class BlackTea implements Drinks {}
public class GreenTea implements Drinks {}

// * 工廠

public class DrinksFactory {

    public Drinks CreateDrinks(String drinks_type) { // ! 函數(向上轉型成 interface Drinks)

        if (drinks_type == null) { return null; }

        // 以下有 20 種飲料...
        switch (drinks_type) {
            case "BlackTea": return new BlackTea();
            case "GreenTea": return new GreenTea();
        }

        return null;
    }
}