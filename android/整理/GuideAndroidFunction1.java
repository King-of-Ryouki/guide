package com.example.test; // 包

import androidx.appcompat.app.AppCompatActivity; // Main

import android.os.LocaleList;
import android.os.Bundle; // 物件封裝資料，藉由 Bundle 來傳遞於不同 Intent 之間
                          // Intent 一般用來跳轉 Activity, or 在兩個 Activity 間傳遞參數

import android.content.res.Configuration;
import android.content.res.Resources;
import android.content.Context;
import android.content.DialogInterface;

import android.graphics.Bitmap; // 圖片
import android.graphics.BitmapFactory;
import android.graphics.Canvas; // 畫布
import android.graphics.Color;
import android.graphics.Paint; // 畫筆
import android.graphics.PaintFlagsDrawFilter;
import android.graphics.Path;
import android.graphics.Rect;
import android.graphics.Region;

import android.text.Editable;
import android.text.TextWatcher;

import android.util.AttributeSet; // AttributeSet attrs // 屬性集
import android.util.DisplayMetrics;
import android.util.Log;

import android.view.Gravity; // 重力
import android.view.inputmethod.InputMethodManager;
import android.view.KeyEvent; // 鍵盤
import android.view.MotionEvent;
import android.view.Menu;
import android.view.MenuItem;

import android.view.View.OnKeyListener;
import android.view.View.OnClickListener;
import android.view.View; // 按鈕

// Layout 佈局
import androidx.constraintlayout.widget.ConstraintLayout;
import android.widget.FrameLayout;
import android.widget.GridLayout;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

import android.widget.TextView;  // 文字
import android.widget.EditText;  // 顯示文字
import android.widget.ImageView; // 圖片
import android.widget.Button;    // 按鈕
import android.widget.Toast;     // 彈跳對話
import android.widget.*;

import java.text.DecimalFormat; // 小數
import java.util.Locale;

// ctrl + i // Select Method to Implement
// ctrl + 6 // LogCat
// Alt + Enter // 構造函數

public class GuideAndroidFunction {

    // public static void main(String[] args) {}

    int guide_android = 1;

    public GuideAndroidFunction() {

        if (guide_android) // MainActivity
        {
            public class MainActivity extends AppCompatActivity {

                @Override
                protected void onCreate(Bundle savedInstanceState) {
                    super.onCreate(savedInstanceState);
                    setContentView(R.layout.activity_main);

                    BottomNavigationView navView = findViewById(R.id.nav_view);
                    // Passing each menu ID as a set of Ids because each
                    // menu should be considered as top level destinations.
                    AppBarConfiguration appBarConfiguration = new AppBarConfiguration.Builder(R.id.navigation_home,
                                                                                              R.id.navigation_dashboard, R.id.navigation_notifications)
                                                                  .build();
                    NavController navController = Navigation.findNavController(this, R.id.nav_host_fragment);
                    NavigationUI.setupActionBarWithNavController(this, navController, appBarConfiguration);
                    NavigationUI.setupWithNavController(navView, navController);
                }

                @Override
                public boolean onCreateOptionsMenu(Menu menu) {
                    getMenuInflater().inflate(R.menu.menu_main, menu); // 菜單擴充.擴充
                    return true;
                }
            }
        }

        if (guide_android) // MainActivity
        {
            public class MainActivity extends AppCompatActivity {

                private ImageView myImageView;

                @Override
                protected void onCreate(Bundle savedInstanceState) {

                    super.onCreate(savedInstanceState);
                    setContentView(R.layout.activity_main);

                    initViews(); // 初始化控制項
                    initData();  // 初始化資料

                    setListeners(); // 設定監聽事件
                }

                private void initViews() {
                    myImageView = (ImageView) findViewById(R.id.imageView1);
                }

                private void initData() {
                }

                private void setListeners() {

                    myImageView.setOnTouchListener(new MyOnTouchListener()); // 呼叫一個新的class

                    // 當要監聽某個接口的時候，同樣的，也需要設定回call的函數名稱
                    // 開發者要告訴程式到底哪一個元件要做這一個反應，因為用戶可以設定

                    imageView1.setOnTouchListener(new MyOnTouchListener());
                    imageView2.setOnTouchListener(new MyOnTouchListener());
                    imageView3.setOnTouchListener(new MyOnTouchListener());
                }

                private final class MyOnTouchListener implements View.OnTouchListener {

                    // 不同元件可以使用同一觸發事件，透過 onTouch 來判斷
                    @Override
                    public boolean onTouch(View v, MotionEvent event) {

                        ImageView t_v = (ImageView) v;

                        if (t_v == myImageView) {
                            Toast.makeText(getApplicationContext(), "您好! Android!", Toast.LENGTH_SHORT).show();
                        }

                        return false;
                    }
                }
            }
        }

        if (guide_android) // onTouch
        {
            onTouchListener(); // 觸摸偵測
            onTouchEvent();    // 觸摸 + 動作
            onTouch();         // 觸摸

            A.setOnTouchListener(new onTouchListener() {
                public boolean onTouch(View v, MotionEvent event) {

                    switch (event.getAction()) {
                        case MotionEvent.ACTION_DOWN: break;
                        case MotionEvent.ACTION_UP: break;
                    }

                    return true; // 还回为true,说明事件已经完成了，不会再被其他事件监听器调用
                }
            });
        }

        if (guide_android) // MotionEvent
        {
            View.OnTouchListener(); // 監聽按下
            onTouch();

            MotionEvent();

            return ACTION_DOWN;   // 按下
            return ACTION_MOVE;   // 移動
            return ACTION_UP;     // 放開
            return ACTION_CANCEL; // 取消

            return ACTION_OUTSIDE; // 超出 UI 邊界

            // 多點觸控
            return ACTION_POINTER_DOWN; // 多點觸控，按下
            return ACTION_POINTER_UP;   // 多點觸控， 放開
        }

        if (guide_android) // MotionEvent, KeyEvent
        {
            private final class MyOnTouchListener implements OnTouchListener {

                @Override
                public boolean onTouch(View v, MotionEvent event) { // 觸摸
                }

                @Override
                public boolean onKey(View v, int keyCode, KeyEvent event) { // 鍵盤

                    switch (event.getAction()) {

                        case KeyEvent.ACTION_UP: // 键盘松开
                            String sAccout = etAccout.getText().toString();
                            tvInfo.setText(Subs(sAccout));

                        case KeyEvent.ACTION_DOWN: // 键盘按下
                            break;
                    }

                    return false;
                }
            }
        }

        if (guide_android) // 多國語系
        {

            public class GuideAndroidFunction {

                // @Override
                protected void onCreate(Bundle savedInstanceState) {

                    super.onCreate(savedInstanceState);

                    Resources res      = getResources();
                    Configuration conf = res.getConfiguration();
                    Locale.setDefault(Locale.SIMPLIFIED_CHINESE);
                    createConfigurationContext(conf);

                    setContentView(R.layout.activity_main);
                }
            }
        }

        if (guide_android) // DashboardViewModel
        {
            public class DashboardViewModel extends ViewModel {

                private MutableLiveData<String> mText;

                public DashboardViewModel() {
                    mText = new MutableLiveData<>();
                    mText.setValue("This is dashboard fragment");
                }

                public LiveData<String> getText() { return mText; }
            }
        }

        if (guide_android) // DashboardFragment
        {
            public class DashboardFragment extends Fragment {

                private DashboardViewModel dashboardViewModel;

                public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {

                    dashboardViewModel      = ViewModelProviders.of(this).get(DashboardViewModel.class);
                    View root               = inflater.inflate(R.layout.fragment_dashboard, container, false);
                    final TextView textView = root.findViewById(R.id.text_dashboard);

                    dashboardViewModel.getText().observe(this, new Observer<String>() {
                        @Override
                        public void onChanged(@Nullable String s) {
                            textView.setText(s);
                        }
                    });

                    return root;
                }
            }
        }

        if (guide_android) // OnClickListener
        {

            if (guide_android) // OnClickListener_1
            {
                class OnClickListener_1 {

                    public OnClickListener_1() {

                        Button btn_1 = (Button) findViewById(R.id.button_1);
                        btn_1.setOnClickListener(btn1Listener);

                        private Button.OnClickListener Btn_1_Listener = new Button.OnClickListener() {
                            @Override
                            public void onClick(View v) {}
                        };
                    }
                }
            }

            if (guide_android) // OnClickListener_2
            {
                class OnClickListener_2 {

                    public OnClickListener_2() {

                        Button btn_2 = (Button) findViewById(R.id.btn_2);

                        btn_2.setOnClickListener(new OnClickListener() {
                            @Override
                            public void onClick(View v) {}
                        });
                    }
                }
            }

            if (guide_android) // OnClickListener_3
            {
                public class MainActivity extends AppCompatActivity implements OnClickListener {

                    @Override
                    protected void onCreate(Bundle savedInstanceState) {
                        super.onCreate(savedInstanceState);
                        setContentView(R.layout.activity_main);

                        ((Button) findViewById(R.id.btn_1)).setOnClickListener(this);
                        ((Button) findViewById(R.id.btn_2)).setOnClickListener(this);
                        ((Button) findViewById(R.id.btn_3)).setOnClickListener(this);
                    }

                    @Override
                    public void onClick(View v) {

                        switch (v.getId()) {

                            case R.id.btn_1:
                                Intent intent_1 = new Intent(MainActivity.this, A.class);
                                startActivity(intent_1);
                                break;

                            case R.id.btn_2:
                                Intent intent_2 = new Intent(MainActivity.this, B.class);
                                startActivity(intent_2);
                                break;

                            case R.id.btn_3:
                                Toast.makeText(MainActivity.this, "Hi", Toast.LENGTH_LONG).show();
                                break;
                        }
                    }
                }
            }
        }

        if (guide_android) // onSizeChanged, onMeasure // 大小
        {
            public class MainActivity extends AppCompatActivity {

                @Override
                protected void onCreate(Bundle savedInstanceState) {
                    super.onCreate(savedInstanceState);
                    setContentView(R.layout.activity_main);
                }

                protected void onSizeChanged(int w, int h, int oldw, int oldh) {}
                protected void onMeasure(int widthMeasure, int heightMeasure) {}
            }
        }

        if (guide_android) // TypedValue.applyDimension, getResources().getDisplayMetrics(), DisplayMetrics // 螢幕尺寸, 解析度
        {
            // !http://dean-android.blogspot.com/2013/09/androiddisplay-metricsdensity-dpi.html
            // !http://joshchangs.blogspot.com/2013/05/getdisplaymetrics.html

            TypedValue.applyDimension();        // 螢幕尺寸
            getResources().getDisplayMetrics(); // 螢幕像素

            class Test {

                private int DipToPx(int dip) {
                    return (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dip,
                                                           getResources().getDisplayMetrics());
                }

                private int DipToPx(int dip) {

                    Resources r = getResources();
                    float px    = TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dip, r.getDisplayMetrics());
                    return (int) px;
                }
            }

            //

            DisplayMetrics metrics = getResources().getDisplayMetrics();

            tv.setText("螢幕資訊:\n");
            tv.append("寬:" + metrics.widthPixels + "\n");
            tv.append("高:" + metrics.heightPixels + "\n");
            tv.append("DPI:" + metrics.densityDpi + "\n");

            if (metrics.widthPixels < metrics.heightPixels) {
                tv.append("目前是直式\n");
            } else {
                tv.append("目前是橫式\n");
            }

            setContentView(tv);

            // 透過 getDisplayMetrics 方法取的裝置解析度以及判斷直 / 橫模式
            // 首先透過 getResources () 方法取得 Resources 物件，再經由 Resources 物件的 getDisplayMetrics ()
            // 方法取得與目前顯示相關的物件 DisplayMetrics，之後再透過 widthPixels (寬) 與 heightPixels (高)
            // 的值來判斷目前顯示是直式 (PORTRAIT Mode) 或橫式 (LANDSCAPE Mode)。
        }

        if (guide_android) //
        {
        }

        if (guide_android) //
        {
        }
    }
}