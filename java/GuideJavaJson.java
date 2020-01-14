// ******************************
// *
// * Author   : 施冠年
// * Date     : 2019/10/25
// * Mail     : Co6901251@gmail.com
// *
// * Function :
// *
// * Java notes : JSON
// *
// ******************************

public class GuideJavaJson {

    public JavaGuideThread() {

        int guide_java_json = 1;

        if (guide_java_json) //
        {
            // JSON 全名為 JavaScript Object Notation
            // 在 Android 網路傳輸資料時經常會使用 JSON 結構來儲存資料
            // 而 JSON 又包含了 JSONObject 與 JSONArray
            // JSONObject 就是 JSON 格式的物件
            // JSONArray 為 JSONObject 所組成的陣列。

            // 物件(object) {}
            // 陣列(array)  []

            // [
            //     { "1": 1 },
            //     { "2": 2 },
            //     { "3": 3 },
            // ];

            // { "subject" : "Math", "score" : 80 } // key : value 的方式儲存, key 一定要用字串

            // 不能使用註解

            // 物件和陣列可以互相轉換
            // 物件 -> 陣列, 就會損失鍵值(key)的資料，留下值(value)，
            // 或是程式到時候指定說，要鍵值陣列(key array)，就會把所有的鍵值(key)合併一起成陣列
            // 若 陣列 -> 物件
            // 就可以將每個值編上數字
        }

        if (guide_java_json) //
        {
            JSONObject json_obj_1 = new JSONObject();

            json_obj_1.put("id", 1);
            json_obj_1.put("info", "json_obj_1");

            json_obj_2.put("id", 2);
            json_obj_2.put("info", "json_obj_2");

            json_obj_1.put("obj", json_obj_2);

            Log.i("text", "json_obj_1 = " + json_obj_1 + "\n"); // 當 JSON + "\n" 就可成為 String 印出, 在傳輸時也必須用 JSON + "\n"

            // ! Res :
            // { "id" : 1,"info" : "json_obj_1",
            //   "obj" : {
            //       "id" : 2, "info" : "json_obj_2"
            //   }
            // }
        }

        if (guide_java_json) //
        {
            try {
                JSONObject jsonObject = new JSONObject(jsonText);
                String name           = jsonObject.getString("name");
                String title          = jsonObject.getString("title");
                String tag            = jsonObject.getString("tag");
                String info           = jsonObject.getString("info");
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
    }
}