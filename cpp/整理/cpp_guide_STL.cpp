// cpp_guide_STL

int guide_STL = 1;

else if // ! cpp reference
{
    // * array         // http://www.cplusplus.com/reference/array/array/
    // * stack         // http://www.cplusplus.com/reference/stack/stack/
    // * queue         // http://www.cplusplus.com/reference/queue/queue/

    // * vector        // http://www.cplusplus.com/reference/vector/vector/
    // * forward_list  // http://www.cplusplus.com/reference/forward_list/forward_list/
    // * list          // http://www.cplusplus.com/reference/list/list/
    // * deque         // http://www.cplusplus.com/reference/deque/deque/

    // * map           // http://www.cplusplus.com/reference/map/map/
    // * set           // http://www.cplusplus.com/reference/set/set/
    // * unordered_map // http://www.cplusplus.com/reference/unordered_map/unordered_map/
    // * unordered_set // http://www.cplusplus.com/reference/unordered_set/unordered_set/
}

if (guide_STL) // STL
{
    // ! 迭代器範圍刪除是前閉後開 [first, last)

    //            * Vector               // * List
    // 随机访问 // * 很快                 // * 很慢(可能要遍历整个链表)
    // 插入     // * 头部：很慢 尾部：很快 // * 很快

    // 另外对于新添加的元素，Vector有一套算法，而List可以任意加入。

    // vector : 高效的随即存取，不在乎插入和删除的效率
    // list   : 大量的插入和删除，而不关心随即存取
    // deque  : 随即存取，而且关心两端数据的插入和删除

    // * STL:
    // array
    // deque
    // forward_list
    // list
    // map
    // queue
    // set
    // stack
    // unordered_map
    // unordered_set
    // vector

    else if // C11 // * emplace
    {
        push_back(); // * 拷貝
        emplace();   // * 構造
        // ! 函数在容器中直接构造元素，传递给emplace函数的参数必须与元素类型的构造函数相匹配。

        // ! e.g. 假定d是一个Date类型的容器 -----
        d.emplace_back("2016", "05", "26");    // 使用三个参数的Date构造函数,在容器管理的内存空间中构造新元素。
        d.push_back("2016", "05", "26");       // 错误，push_back 没有这种用法
        d.push_back(Date("2016", "05", "26")); // push_back() 创建一个临时对象，然后将临时对象拷贝到容器中

        // emplace 类似 insert
        // emplace_back 类似 push_back
    }

    else if // vector iterator
    {
        vector<int>::iterator iter;

        // ! 使用迭代器读取vector中的每一个元素 -----
        vector<int> vec_1(10, 1);
        for (vector<int>::iterator iter = vec_1.begin();
             iter != vec_1.end();
             ++iter) {
            *iter = 2; //使用 * 访问迭代器所指向的元素
        }

        // ! const_iterator: -----
        // 只能读取容器中的元素，而不能修改
        for (vector<int>::const_iterator citer = ivec.begin();
             citer != ivec.end();
             ++citer) {
            cout << *citer;
            // *citer = 3; // error
        }

        // vector<int>::const_iterator 和
        // const vector<int>::iterator 的区别

        const vector<int>::iterator newiter = ivec.begin();

        *newiter = 11; // 可以修改指向容器的元素
        // newiter++;  // 迭代器本身不能被修改

        // iterator 的算术操作：
        // iterator 除了进行 ++ -- 操作，可以将iter+n,iter-n 赋给一个新的 iteraor 对象。
        // 还可以使用一个 iterator 减去另外一个 iterator
        const vector<int>::iterator newiter = ivec.begin();
        vector<int>::iterator newiter2      = ivec.end();
        cout << newiter2 - newiter;
    }

    if // vector // #include <vector>
    {
        // #include <vector>

        // ! 迭代器範圍刪除是前閉後開 [first, last)
        // ! { 0, 1, 2, 3, 4, 5 }
        // !   ^begin()        , ^end()

        // 尾端增刪 O(1)
        // 中間增刪 O(n)
        // 支援隨機存取

        vector<int> vec;                  // * 僅宣告
        vector<int> vec{ 1, 2, 3, 4, 5 }; // *  5個空間
        vector<int> vec(10);              // * 10個空間
        vector<int> vec(10, 5);           // * 10個空間, var = 5

        vector<vector<int>> x; // 當二維陣列使用

        int arr_1[] = { 0, 1, 2, 3, 4, 5 };
        vector<int> vec(arr_1, arr_1 + sizeof(arr_1) / sizeof(arr_1[ 0 ])); // ! res : { 0, 1, 2, 3, 4, 5 }
        vector<int> vec(arr_1, arr_1 + 6);                                  // ! res : { 0, 1, 2, 3, 4, 5 }

        vector<int> vec_1(5, 1);
        vector<int> vec_2(vec_1);
        vector<int> vec_3 = vec_2;

        // * //////////////////////////////////////////////////////////////////////////////////////////////////

        int arr_1[] = { 0, 1, 2, 3, 4 };
        vector<int> vec_1(arr_1, arr_1 + sizeof(arr_1) / sizeof(arr_1[ 0 ]));

        cout << vec_1[ 2 ] << endl;    // ! res : 2
        cout << vec_1.at(2) << endl;   // ! res : 2
        cout << vec_1.front() << endl; // ! res : 1
        cout << vec_1.back() << endl;  // ! res : 4

        // vec_1[ i ];    // * 索引值 i 的元素值 // ! operator[] 可能會 segmentation fault
        // vec_1.at(i);   // * 索引值 i 的元素值 // ! 有陣列邊界檢查, 如果存取越界將會拋出一個例外
        // vec_1.front(); // * vector 首元素值
        // vec_1.back();  // * vector 尾元素值

        // vec_1.push_back(); // * 新增元素至 vector 的尾端，必要時會進行記憶體配置。
        // vec_1.pop_back();  // * 刪除尾端元素。
        // vec_1.insert();    // * 插入一個或多個元素至 vector 內的任意位置。
        // vec_1.erase();     // * 刪除 vector 中一個或多個元素。
        // vec_1.clear();     // * 清空所有元素。

        // vec_1.empty();             // * 如果 vector 內部為空，則傳回 true 值。
        // vec_1.size();              // * 取得 vector 目前持有的元素個數。
        // vec_1.resize();            // * 改變 vector 目前持有的元素個數。
        // vec_1.capacity();          // * 取得 vector 目前可容納的最大元素個數。這個方法與記憶體的配置有關，它通常只會增加，不會因為元素被刪減而隨之減少。
        // vec_1.shrink_to_fit();     // * 將 capacity() 減至 .size()
        // vec_1.reserve();           // * 如有必要，可改變 vector 的容量大小（配置更多的記憶體）。在眾多的 STL 實做，容量只能增加，不可以減少。
        // vec_1.swap(vec_2);         // * 交換

        int arr_1[] = { 1, 2, 3 };
        vector<int> vec_1(arr_1, arr_1 + sizeof(arr_1) / sizeof(arr_1[ 0 ]));

        vec_1.push_back(0);              // 尾端加入 0 // ! res : { 1, 2, 3, 0 }
        vec_1.insert(vec.begin(), 2, 0); // 插入 2 個 0 // ! res : { 0, 0, 1, 2, 3 }

        // push_back() 的效率問題
        //
        // 少依賴 push_back() 的自動記憶體配置，不是不要用 push_back，是不要讓 push_back 自己判定記憶體需求，
        // 能自己要記憶體的就自己要，善用 reserve()、resize() 或 constructor 引數。

        // 這個是 STL 迭代器相關函式的設計原則，區間範圍以前閉後開範圍表示，例如，用 erase() 刪除全部元素
        // vec.erase( vec.begin(), vec.end() )，vec.begin() 是在第一個元素, vec.end() 是最後一個元素的下一個元素。

        // empty() 和 size() == 0
        //
        // 不建議使用 size() == 0 判斷容器是否為空，用 empty() 判斷較恰當。因為並不是所有容器的 size() 都是 O(1) ，
        // 例如 <list> 是 linked list 結構，其 size() 是 O(n)。

        // * ^^^^^ 取得長度/容量的用法 ^^^^^

        // 4. 疊代 (Iterator)
        //
        // vec.begin() - 回傳一個 iterator，它指向 vector 第一個元素。
        // vec.end() - 回傳一個 iterator，它指向 vector 最尾端元素的下一個位置（請注意：它不是最末元素）。
        // vec.rbegin() - 回傳一個反向 iterator，它指向 vector 最尾端元素的。
        // vec.rend() - 回傳一個 iterator，它指向 vector 的第一個元素。
    }

    else if // forward_list // 單鏈表(singly linked list)
    {
        // 單鏈表(singly linked list)
        // ! forward_list 在容器內任意位置的成員的插入、提取（extracting）、移動、刪除操作的速度更快，因此被廣泛用於排序算法
        // 優點： 由於只有指向下一個表項的連結，因此具有插入、刪除表項速度快、消耗內存空間少的特點。
        // 缺點： 只能向前遍歷。

        // 雙鏈表(doubly linked list)
        // 有"前後"兩個指針，可以雙向遍歷，但消耗內存空間更多，插入或刪除成員時的速度稍慢。
        // 与 vector 相比，允许快速的插入和删除，但是随机访问却比较慢。

    }

    else if // list // 雙鏈表(doubly linked list)
    {
        // 在存储复杂类型和大量元素的情况下，list比vector更有优势！
        //
        // list每次增加一个元素，不存在重新申请内存的情况，它的成本是恒定的。
        // 而vector每当增加关键元素的时候，都需要重新申请新的更大的内存空间，会调用元素的自身的复制构造函数，存在构造成本。
        // 在销毁旧内存的时候，会调用析构函数，存在析构成本。

        // 存儲所包含的每個成員在不同、不相關的位置；順序保持是通過關聯每個成員與其在序列中的下一個成員。

        // 單鏈表(singly linked list)
        // forward_list 在容器內任意位置的成員的插入、提取（extracting）、移動、刪除操作的速度更快，因此被廣泛用於排序算法
        // 優點： 由於只有指向下一個表項的連結，因此具有插入、刪除表項速度快、消耗內存空間少的特點。
        // 缺點： 只能向前遍歷。

        // 雙鏈表(doubly linked list)
        // 有"前後"兩個指針，可以雙向遍歷，但消耗內存空間更多，插入或刪除成員時的速度稍慢。
        // 与 vector 相比，允许快速的插入和删除，但是随机访问却比较慢。

        // assign()        // 给list赋值
        // back()          // 返回最后一个元素
        // begin()         // 返回指向第一个元素的迭代器
        // clear()         // 删除所有元素
        // empty()         // 如果list是空的则返回true
        // end()           // 返回末尾的迭代器
        // erase()         // 删除一个元素
        // front()         // 返回第一个元素
        // get_allocator() // 返回list的配置器
        // insert()        // 插入一个元素到list中
        // max_size()      // 返回list能容纳的最大元素数量
        // merge()         // 合并两个list
        // pop_back()      // 删除最后一个元素
        // pop_front()     // 删除第一个元素
        // push_back()     // 在list的末尾添加一个元素
        // push_front()    // 在list的头部添加一个元素
        // rbegin()        // 返回指向第一个元素的逆向迭代器
        // remove()        // 从list删除元素
        // remove_if()     // 按指定条件删除元素
        // rend()          // 指向list末尾的逆向迭代器
        // resize()        // 改变list的大小
        // reverse()       // 把list的元素倒转
        // size()          // 返回list中的元素个数
        // sort()          // 给list排序
        // splice()        // 合并两个list
        // swap()          // 交换两个list
        // unique()        // 删除list中重复的元素
    }

    else if // 堆疊系 queue || deque || stack
    {
        else if // queue 隊列(隧道(堆疊頭尾))
        {
            // #include <queue>
            // using std::queue;

            // ! vvvvv e.g. vvvvv

            // |  data1  | <-- pop  || front
            // |  data2  |
            // |  data3  | <-- push || back

            // ! ^^^^^ e.g. ^^^^^

            // 可以快速的把頭的值拿掉
            // 只能操作頭跟尾

            queue<int> queue_1;

            queue_1.pop();    // 刪除首元素
            queue_1.push(10); // 加入尾元素

            queue_1.front(); // 返回首元素
            queue_1.back();  // 返回尾元素

            queue_1.size();  // 元素個數
            queue_1.empty(); // if (queue == NULL) { return true; }
        }

        else if // deque // 双端队列 double-end queue
        {
        }

        else if // stack 堆疊(盤子(堆疊頭))
        {
            // #include <stack>
            // using std::stack;

            // ! vvvvv e.g. vvvvv
            // ! 盤子

            // |  data1  |
            // |  data2  |
            // |  data3  |
            // |_________|

            // ! ^^^^^ e.g. ^^^^^

            stack<int> stack_1;

            stack_1.pop();  // 刪除首元素
            stack_1.push(); // 加入首元素

            stack_1.(); // 返回首元素

            stack_1.size();  // 元素個數
            stack_1.empty(); // if (stack == NULL) { return true; }
        }
    }

    else if // set // 集合 // 檢查包含某元素
    {
        // insert: 把一個數字放進集合
        // erase: 把某個數字從集合中移除
        // count: 檢查某個數是否有在集合中

        set<int> set_1;
        set_1.erase();
        // iterator  erase (const_iterator position); // * 刪除迭代
        // size_type erase (const value_type& val); // * 刪除值
        // iterator  erase (const_iterator first, const_iterator last); // * 刪除範圍

        set_1.find(); //返回一個指向被查詢到元素的迭代器

        int arr_1[] = { 12, 75, 10, 32, 20, 25 };
        set<int> set_2(arr_1, arr_1 + 3);     // 10,12,75
        set<int> set_3(arr_1 + 3, arr_1 + 6); // 20,25,32
        set_2.swap(set_3);
        // ! res : set_2 : 20, 25, 32
        // ! res : set_3 : 10, 12, 75

        // * -----
        set_1.begin();  // 返回首元素
        set_1.end();    // 返回尾元素
        set_1.rbegin(); // 反向 iterator
        set_1.rend();   // 反向 iterator

        set_1.count(2); // 找值

        set_1.size();     // set容器中的元素個數
        set_1.max_size(); // set容器能夠包含的最大元素個數

        set_1.clear(); // 删除所有元素
        set_1.empty(); // if (set == NULL) { return true; }
    }

    else if // map // 對應表
    {
        // #include <map>

        // http://mropengate.blogspot.com/2015/12/cc-map-stl.html
        // https://www.cnblogs.com/fnlingnzb-learner/p/5833051.html

        // map : 紅黑樹 (查询、插入、删除都是O(logn) )
        // unordered_map : hash 結構，C++11 標準函式庫。
        // unordered_set : hash 結構，但 value 本身即是 key。
        // hash_map : hash 結構，非標準函式庫。

        // Map 的優點
        // 設定對應值很簡單
        // 用很高的效率找到對應值

        // Map 的缺點
        // 對應值越多會越慢

        // 基本功能有:
        // []: 得到對應的值
        // count: 檢查某個值是否有對應值

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // 成員函式簡介與常用程式寫法

        // 1. 宣告
        map<string, string> map_1;

        // 2. 插入 insert()
        // 用 insert 函數插入 pair
        map_1.insert(pair<string, string>("r000", "student_zero"));

        //用 "array" 方式插入
        map_1[ "r123" ] = "student_first";
        map_1[ "r456" ] = "student_second";

        cout << "map_1[r123] = " << map_1[ r123 ] << endl;
        // map_1[r123] = student_first

        // 3. 尋找 find()
        // 出現時，它返回資料所在位置，如果沒有，返回 iter 與 end() 函數的返回值相同。

        iter = map_1.find("r123");

        if (iter != map_1.end()) {
            cout << "Find, the value is" << iter->second << endl;
        } else {
            cout << "Do not Find" << endl;
        }

        // ----------
        // 4. 刪除與清空
        // 清空 map 中的資料可以用 clear() 函數，判定 map 中是否有資料用 empty() 函數，
        // 如果回傳 true 則 map 為空，而資料的刪除用 erase() 函數，它有三種 overload 的用法：

        //迭代器刪除
        iter = map_1.find("r123");
        map_1.erase(iter);

        //用關鍵字刪除
        int n = map_1.erase("r123"); //如果刪除了會返回1，否則返回0

        //用迭代器範圍刪除 : 把整個map清空
        map_1.erase(map_1.begin(), map_1.end());
        //等同於 map_1.clear()

        // 5. 用法彙整

        // #include <iostream>
        // #include <map>
        // #include <string>

        using namespace std;

        int main() {
            // declaration container and iterator
            map<string, string> map_1;
            map<string, string>::iterator iter;
            map<string, string>::reverse_iterator r_iter;

            // insert element
            map_1.insert(pair<string, string>("r000", "student_zero"));

            map_1[ "r123" ] = "student_first";
            map_1[ "r456" ] = "student_second";

            // traversal
            for (iter = map_1.begin(); iter != map_1.end(); iter++) {
                cout << iter->first << " " << iter->second << endl;
            }
            for (r_iter = map_1.rbegin(); r_iter != map_1.rend(); r_iter++) {
                cout << r_iter->first << " " << r_iter->second << endl;
            }

            // find and erase the element
            iter = map_1.find("r123");
            map_1.erase(iter);

            iter = map_1.find("r123");

            if (iter != map_1.end()) {
                cout << "Find, the value is " << iter->second << endl;
            } else {
                cout << "Do not Find" << endl;
            }

            return 0;
        }
    }

    else if // Hash Table
    {
        // 以實用的角度出發，在簡單認識 Hash Table 的時候並不需要理解 hash function 要怎麼實作，
        // 但是我們要知道，hash function沒有完美的，有可能會把兩個不同的 key 指到同一個桶子，這就是所謂的 collision。
        // 當 collision 發生的時候，除了最直觀地增加 Hash Table 的桶子數，
        // 在每個桶子中用一個 linked list 來儲存 value、或是 linear probe 都是常用的方法

        // 不該使用 Hash Table 的時候。
        // 例如想要處理一些有時間順序的 data，希望可以丟掉最先進來的資料優先，queue 顯然就是一個更好的選擇。
        // 還有一個情況是，如果希望儲存的 data 可以被排序，那 Hash Table 就會不太好用。

        // Hash Table 的應用
        // 例如在搜尋的時候輸入關鍵字，我們可以把這個關鍵字傳進 hash function，
        // 然後 hash function 就可以指出這個關鍵字對應到的桶子，這時候再到這個桶子裡搜尋網頁就可以了。
    }
}

if (guide_STL) // bitset
{
    // #include <bitset>
    // using std::bitset;
}