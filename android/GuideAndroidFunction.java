public class GuideAndroidFunction {

    // public static void main(String[] args) {}

    int guide_android = 1;

    public GuideAndroidFunction() {

        if (guide_android) // layout 更換
        {
            if (guide_android) // findViewById, LayoutInflater, inflate, setContentView // 獲得控件 // 佈局 頁面跳轉
            {
                // 實體控件
                LinearLayout layout_display_;
                layout_display_ = (LinearLayout) findViewById(R.id.layout_display);

                // new 控件
                LayoutInflater inflater = getLayoutInflater(); // Activity 限定
                LayoutInflater inflater = LayoutInflater.from(this);
                LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);

                View view = inflater.inflate(R.layout.layout_1, null);
                setContentView(view); // 顯示

                //

                // LayoutInflater 是用來找 res/layout/ 下的 xml 佈局文件，並且實例化
                // findViewById () 是找 xml 佈局文件下的具體 widget 控件 (如 Button、TextView 等)

                // 具體作用：
                // 1、對於一個沒有被載入或者想要動態載入的界面，都需要使用 LayoutInflater.inflate () 來載入；
                // 2、對於一個已經載入的界面，就可以使用 Activiyt.findViewById () 方法來獲得其中的界面元素。
            }

            if (guide_android) // View, inflate, setContentView 更換 layout
            {
                // * setContentView

                setContentView(R.layout.layout_1); // 可在 layout 之間轉換，但仍然使用同個 Activity

                // setContentView () 一旦调用，layout 就会立刻显示 UI；
                // 而 inflate 只会把 Layout 形成一个以 view 类实现成的对象，
                // 有需要时再用 setContentView (view) 显示出来，
                // 一般在 activity 中通过 setContentView () 将界面显示出来，
                // 但是如果在非 activity 中如何对控件布局设置操作了，这需 LayoutInflater 动态加载。

                // * View.inflate

                // ! https://blog.csdn.net/zsr_251/article/details/39212571

                View view = View.inflate(this, R.layout.activity_main, null);
                setContentView(view);

                // view 定义要显示的页面，setContentView 就是设置一个 Activity 的显示界面

                // 使用 setContentView 可以在 Activity 中动态切换显示的 View, 这样，不需要多个 Activity 就可以显示不同的界面，
                // 因此不再需要在 Activity 间传送数据，变量可以直接引用。
                // 但是，在 android SDK 给我们建的默认的 Hello World 程序中，调用的是 setContentView (int layoutResID) 方法，
                // 如果使用该方法切换 view, 在切换后再切换回，无法显示切换前修改后的样子，也就是说，相当于重新显示一个 view, 并非是把原来的 view 隐藏后再显示。

                // 其实 setContentView 是个多态方法，我们可以先用 LayoutInflater 把布局 xml 文件引入成 View 对象，
                // 再通过 setContentView (View view) 方法来切换视图。
                // 因为所有对 View 的修改都保存在 View 对象里，所以，当切换回原来的 view 时，就可以直接显示原来修改后的样子。
            }
        }

        if (guide_android) // ! addView 注意要點
        {
            TextView txt = new TextView(getContext());
            txt.setText("A");

            LinearLayout linear_layout       = new LinearLayout(getContext());
            LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT,
                                                                             LinearLayout.LayoutParams.MATCH_PARENT);
            linear_layout.setLayoutParams(params);

            // ! MainActivity 內

            // addView(txt, params);               // ! Error
            // addView(txt);                       // ! Error
            // linear_layout.addView(txt, params); // ! Pass
            // linear_layout.addView(txt);         // ! Pass

            // ! MainActivity 外(繼承 Layout)

            // addView(txt, params);               // ! Pass
            // addView(txt);                       // ! Pass
            // linear_layout.addView(txt, params); // ! Error
            // linear_layout.addView(txt);         // ! Error
        }

        if (guide_android) // LayoutParams, addView
        {
            LinearLayout linear_layout = (LinearLayout) findViewById(R.id.linear_layout);
            linear_layout.addView(root_layout);

            TextView txt                     = new TextView(getContext());
            LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(48, 48);
            addView(txt, params);
        }

        if (guide_android) // LayoutParams, setLayoutParams, addView | 佈局參數
        {
            // 方法 1

            setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT)); // (寬, 高)

            // 方法 2

            TextView txt_ = new TextView(getContext());
            txt_.setText("Test");
            txt_.setTextSize(32);
            txt_.setGravity(Gravity.CENTER); // 置中 // ! 不可 txt_.gravity = Gravity.CENTER;

            FrameLayout.LayoutParams params;
            params         = new FrameLayout.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT); // (寬, 高)
            params.gravity = Gravity.CENTER;
            addView(txt_, params);        // 加入控件至佈局
            txt_.setLayoutParams(params); // 控件套用佈局參數
        }

        if (guide_android) // setText, setTextSize // 文字設定
        {
            TextView txt_1;

            txt_1.setText("" + tile_num_);
            txt_1.setTextSize(24); // px // ! 需用 TypedValue.applyDimension 轉換
        }

        if (guide_android) // Padding, Margins // 邊距
        {
            btn_1.setPadding(5, 0, 5, 0); // 向內
            btn_1.setMargins(5, 0, 5, 0); // 向外
        }

        if (guide_android) // Intent
        {
            Intent intent_1 = new Intent();
            intent_1.setClass(A.this, B.class);
            startActivity(intent_1);

            // * -----

            Intent intent_2 = new Intent(A.this, B.class);
            startActivity(intent_2); // 執行要去的 Activity

            A.this.finish(); // 結束目前 Activity

            // * -----

            // Intent + Bundle

            // * 從 A.class 跳到 B.class

            // * A.class(傳送資料)

            Intent intent = new Intent(); // 指定要切換的 class
            intent.setClass(A.this, B.class);

            Bundle bundle = new Bundle(); // 將要傳遞的資料傳入 Bundle 物件
            bundle.putString("KEY_HEIGHT", num_height.getText().toString());
            bundle.putString("name", name); // 傳遞 String

            intent.putExtras(bundle); // 將Bundle物件傳給intent // 可放所有基本型別
            startActivity(intent);    // 切換 Activity

            // * B.class(接收資料)

            Bundle bundle_b_1 = getIntent().getExtras();
            String name       = bundle_b_1.getString("name");
            double age        = bundle_b_1.getDouble("age");
        }

        if (guide_android) // Toast
        {
            Toast.makeText(MainActivity.this, "要先輸入身高體重喔!", Toast.LENGTH_SHORT).show();
            Toast.makeText(MainActivity.this, "要先輸入身高體重喔!", Toast.LENGTH_LONG).show();
            Toast.makeText(getApplicationContext(), "您好!Android!", Toast.LENGTH_SHORT).show();
        }

        if (guide_android) //
        {
        }

        if (guide_android) //
        {
        }
    }
}