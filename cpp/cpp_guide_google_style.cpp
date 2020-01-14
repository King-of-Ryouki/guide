// ! 來源 : https://tw-google-styleguide.readthedocs.io/en/latest/contents.html

// 文件命名全部小寫，可以包含底線'_' 或連字符'-'.
// 按專案約定來. 如果並沒有專案約定, '_'更好.

// 底線與減號 ( _ vs - )
// 在 JavaScript 中推薦減號, 但個人推薦底線
// 原因 : 在變數上按 ctrl + shift + (左 / 右) 或是左鍵連點都無法一次選取
#include "cpp_guide_google_style.hpp"
#include "cpp-guide-google-style.hpp"

// 命名空間用小寫字母命名，並基於專案名稱和目錄結構: google_awesome_project.
// * C++ namespace == Java package
namespace name_space
{} // namespace name_space

int name;                   // 一般 : 變數名小寫，單詞之間用底線連接
int g_name;                 // 全域 : g_ + 變數名
const int kDaysInAWeek = 7; // 常數 : k + 大駝峰

class Name {
private:
    int name_; // 類成員變數，底線結尾，區別普通變數
    int name;  // 不使用底線結尾

public:
    void set_name(int name) { name_ = name; }     // 類成員變數，底線結尾，區別普通變數
    void set_name(int name) { this.name = name; } // 不使用底線結尾
};

// Setter and getter :
// set_name // set 變數
// setOnClickListener(); // set 函數

// ! 除上之外，基本都是大駝峰

// 大駝峰 : 類, 結構體, 類型定義 (typedef), using, 函數, 類型模板參數

using PropertiesMap = hash_map<UrlTableProperties *, string>; // using 大駝峰

typedef hash_map<UrlTableProperties *, string> PropertiesMap; // 類型定義 大駝峰

class Name {}; // 類名 大駝峰

void Test(); // 函數 大駝峰

enum UrlTableErrors { // 枚舉 常數

    kOK = 0,
    kErrorOutOfMemory,
    kErrorMalformedInput,

};