else if // 8 种常用数据结构
{
    // 数组
    // 栈
    // 队列
    // 链表
    // 图
    // 树
    // 前缀树
    // 哈希表
    //
    // 字典樹(這是一種高效的樹形結構，但值得單獨說明)
    // 散列表(哈希表)

    // 堆疊 (Stack) (又稱棧或堆棧)
    // 佇列 (Queue) (又稱隊列)
    // 陣列 (Array)
    // 連結串列 (Linked List)
    // 樹 (Tree)
    // 圖 (Graph)
    // 堆積 (Heap)
    // 雜湊表 (Hash table)
}

else if // push_back() && insert()
{
}

else if // 非指標型
{
    else if // 陣列(數列) // * 空間成本開銷很少；但陣列需要修改時則空間的複雜性相對比較差（已排序的陣列結構，與搜尋樹相比）。
    {
        else if // 陣列
        {
            int a[ 7 ] = { [4] = 29, 33, [2] = 15 };
            // 相當於
            int a[ 7 ] = { 0, 0, 15, 0, 29, 33, 0 };

            if // 參考陣列
            {
                // !v| e.g. 參考陣列 -----

                int arr_1[] = { 10, 20, 30, 40, 50 };

                int main() {
                    int &ref_arr_1(int i) { return arr_1[ i ]; } // 返回第 i 個元素的參考

                    ref_arr_1(1) = 200; // 改變第 2 個元素
                    ref_arr_1(3) = 400; // 改變第 4 個元素

                    system("pause");
                    return 0;
                }

                // !^| e.g. 參考陣列 -----
            }

            else if // 指向陣列的指標
            {
                double arr_1[ 10 ];
                double *arr_2;

                arr_2 = arr_1;

                // 功能相同
                cout << *(arr_2 + i) << endl;
                cout << *(arr_1 + i) << endl;
            }

            else if // 傳遞陣列給函數
            {
                void myFunction(int *param){};      // 參數是一個指標
                void myFunction(int param[ 10 ]){}; // 參數是一個已定義大小的陣列
                void myFunction(int param[]){};     // 參數是一個未定義大小的陣列

                double Get_ArrAvg(int test_arr[], int arr_qry) {
                    double arr_avg = 0, arr_sum = 0;

                    for (int i = 0; i < arr_qry; i++) {
                        arr_sum += test_arr[ i ];
                    } // 加總

                    arr_avg = double(arr_sum) / arr_qry; // 求平均
                    return arr_avg;
                }

                int test_arr[ 5 ] = { 10, 20, 30, 40, 50 };
                test_arr_avg      = Get_ArrAvg(test_arr, 5); // return arr_avg;
            }

            else if // 從函數返回陣列
            {
                // #include "_pch.hpp"

                int *get_array() {
                    int test_arr[] = { 10, 20, 30, 40, 50 };

                    return test_arr;
                }

                int main() {

                    int *ptr_array_1;
                    ptr_array_1 = get_array(); // test_arr[5]

                    cout << ptr_array_1[ 4 ] << endl;

                    system("pause");
                    return 0;
                }
            }
        }
    }

    else if // 堆疊 (Stack) (又稱棧或堆棧)
    {
        // * 特性：
        // 後進先出 (LIFO, Last-In-First-Out)
        // 除頭尾節點之外，每個元素有一個前驅，一個後繼。

        // * 操作：
        // 推入（壓棧，push）和彈出（彈棧，pop）：
        //
        // 推入：將數據放入堆疊頂端，堆疊頂端移到新放入的數據。
        // 彈出：將堆疊頂端數據移除，堆疊頂端移到移除後的下一筆數據。

        // * 操作：
        // Push    // 在栈的最上方插入元素
        // Pop     // 返回栈最上方的元素，并将其删除
        // isEmpty // 查询栈是否为空
        // Top     // 返回栈最上方的元素，并不删除

        // * 實現：
        // 堆疊可以用陣列和連結串列兩種方式實現，一般為一個堆疊預先分配一個大小固定且較合適的空間並非難事，
        // 所以較流行的做法是Stack結構下含一個陣列。如果空間實在緊張，也可用連結串列實現，且去掉表頭。
    }

    else if // 佇列 (Queue) (又稱隊列) // 刪除： O(1)
    {
        // * 時間複雜度：
        // 算法  平均  最差
        // 空間  O(n)  O(n)
        // 搜尋  O(n)  O(n)
        // 插入  O(1)  O(1)
        // 刪除  O(1)  O(1)

        // * 特點：
        // 先進先出 (FIFO, First-In-First-Out)

        // 具體應用中通常用鍊表或者數組來實現。
        // 佇列只允許在後端（稱為rear）進行插入操作，
        // 在前端（稱為front）進行刪除操作。
        // 佇列的操作方式和堆疊類似，唯一的區別在於佇列只允許新數據在後端進行添加。

        // 單鏈佇列
        // 單鏈佇列使用鍊表作為基本數據結構，所以不存在偽溢出的問題，佇列長度也沒有限制。但插入和讀取的時間代價較高
    }
}

else if // 連結串列 (Linked List)
{
    // 一種線性表，但是並不會按線性的順序儲存數據，而是在每一個節點裏存到下一個節點的指標(Pointer)。
    // 由於不必須按順序儲存，連結串列在插入的時候可以達到 O(1) 的複雜度，比另一種線性表順序表快得多，
    // 尋找一個節點或者存取特定編號的節點 O(n)，
    // 順序表相應的時間複雜度分別是 O(logn) 和 O(1)

    // * 種類
    // 單向連結串列 |data|next_ptr| -> |data|next_ptr| -> |data|X|
    // 雙向連結串列 |X|data|next_ptr| -> |front_ptr|data|next_ptr| -> |front_ptr|data|X|
    // 迴圈連結串列
    // 塊狀連結串列

    // 塊狀連結串列
    // 塊狀連結串列本身是一個連結串列，但是連結串列儲存的並不是一般的數據，而是由這些數據組成的順序表。
    // 每一個塊狀連結串列的節點，也就是順序表，可以被叫做一個塊。
    // 塊狀連結串列通過使用可變的順序表的長度和特殊的插入、刪除方式，可以在達到 O(sqrt(n)) 的複雜度。
    // 塊狀連結串列另一個特點是相對於普通連結串列來說節省記憶體，因為不用儲存指向每一個數據節點的指標。
}

else if // 樹 (Tree)
{
}

else if // 圖 (Graph)
{
}

else if // 堆積 (Heap)
{
}

else if // 雜湊表 (Hash table)
{
}

else if // 二元樹的走訪
{
    //       5
    //      / \
    //     4   6
    //    /     \
    //   2       8
    //  / \     / \
    // 1   3   7   9

    // 前序 : 5, 4, 2, 1, 3, 6, 8, 7, 9
    // 中序： 1, 2, 3, 4, 5, 6, 7, 8, 9
    // 後序 : 1, 3, 2, 4, 7, 9, 8, 6, 5

    // 中序： 1, 2, 3, 4, 5, 6, 7, 8, 9
    void print_in_order(node * ptr) {
        cout << "in order : " << endl;
        if (ptr != nullptr) {
            print_in_order(ptr->left);
            cout << ptr->data << ", " << endl;
            print_in_order(ptr->right);
        }
    }

    //       A
    //      / \
    //     B   C
    //    / \   \
    //   D   E   F
    //  / \   \
    // G   H   I

    // * 前序(Pre-order)  : ABDGHEICF
    // * 中序(In-order)   : GDHBEIACF
    // * 後序(Post-order) : GHDIEBFCA

    // 前序遍歷：   根節點->左子節點->右子節點 根排在前面
    // 中序遍歷： 左子節點->  根節點->右子節點 根排在中間
    // 後序遍歷： 左子節點->右子節點->  根節點 根排在後面
    // 層序遍歷： 順序是由根節點一層一層往下，由左往右。

    // * -----
    //       A
    //      / \
    //     B   C
    //    / \   \
    //   D   E   F
    //  / \   \
    // G   H   I

    // * 廣度優先(Breadth-first) (Level-order)
    // 將每一個階層的節點都走訪完後才到下一層。
    // 圖一的走訪順序為：ABCDEFGH
    // 圖二的走訪順序為：ABCDEFG
}

else if // 二元樹的走訪(遞迴)
{
    // 二叉樹結點的定義
    // 每個二叉樹結點包括一個值以及左孩子和右孩子結點，其定義如下：

    class TreeNode {
    public:
        TreeNode(int var) {
            this->var   = var;
            this->left  = nullptr;
            this->right = nullptr;
        }

        int var;

        TreeNode *left;
        TreeNode *right;
    };

    // 遞迴遍歷
    // 遞迴實現非常簡單，按照遍歷的次序，對當前結點分別呼叫左子樹和右子樹即可。

    // 前序遍歷
    void PreOrder(TreeNode * Root) {

        if (Root == NULL) { return; }

        cout << Root->var << endl;
        PreOrder(Root->left);
        PreOrder(Root->right);
    }

    // 中序遍歷
    void InOrder(TreeNode * Root) {

        if (Root == NULL) { return; }

        InOrder(Root->left);
        cout << Root->var << endl;
        InOrder(Root->right);
    }

    // 後序遍歷
    void PostOrder(TreeNode * Root) {

        if (Root == NULL) { return; }

        PostOrder(Root->left);
        PostOrder(Root->right);
        cout << Root->var << endl;
    }
}

else if // 二元樹的走訪(非遞迴 stack)
{
    // 二叉樹遍歷的非遞迴實現，可以藉助棧。

    class TreeNode {
    public:
        TreeNode(int var) {
            this->var   = var;
            this->left  = nullptr;
            this->right = nullptr;
        }

        int var;

        TreeNode *left;
        TreeNode *right;
    };

    // 前序遍歷
    // 將根結點入棧；
    // 每次從棧頂彈出一個結點，訪問該結點；
    // 把當前結點的右孩子入棧；
    // 把當前結點的左孩子入棧。
    // 按照以上順序入棧，這樣出棧順序就與先序遍歷一樣：先根結點，再左子樹，最後右子樹。
    void preOrder2(TreeNode * Root) {

        if (Root == nullptr) { return; }

        stack<TreeNode *> stack_TreeNode;
        stack_TreeNode.push(Root); // stack { Root } // 將根結點入棧

        while (!stack_TreeNode.empty()) {

            TreeNode *ptr_TreeNode = stack_TreeNode.top();
            stack_TreeNode.pop(); // 每次從棧頂彈出一個結點，訪問該結點

            cout << ptr_TreeNode->var << endl;
            if (ptr_TreeNode->right != nullptr) { stack_TreeNode.push(ptr_TreeNode->right); } // 把當前結點的右孩子入棧
            if (ptr_TreeNode->left != nullptr) { stack_TreeNode.push(ptr_TreeNode->left); }   // 把當前結點的左孩子入棧
        }
    }

    // 中序遍歷
    // 初始化一個二叉樹結點 ptr_TreeNode 指向根結點；
    // 若 ptr_TreeNode 非空，那麼就把 ptr_TreeNode 入棧，並把 ptr_TreeNode 變為其左孩子；（直到最左邊的結點）
    // 若 ptr_TreeNode 為空，彈出棧頂的結點，並訪問該結點，將 ptr_TreeNode 指向其右孩子（訪問最左邊的結點，並遍歷其右子樹）
    void inOrder2(TreeNode * Root) {

        if (Root == nullptr) { return; }

        stack<TreeNode *> stack_TreeNode;
        TreeNode *ptr_TreeNode = Root; // 初始化一個二叉樹結點 ptr_TreeNode 指向根結點

        while (ptr_TreeNode != nullptr || !stack_TreeNode.empty()) {

            if (ptr_TreeNode != nullptr) {

                stack_TreeNode.push(ptr_TreeNode);

                ptr_TreeNode = ptr_TreeNode->left;

            } else {

                ptr_TreeNode = stack_TreeNode.top();
                stack_TreeNode.pop();

                cout << ptr_TreeNode->var << endl;

                ptr_TreeNode = ptr_TreeNode->right;
            }
        }
    }

    // 後序遍歷
    // 設定兩個棧stk, stk2；
    // 將根結點壓入第一個棧stk；
    // 彈出stk棧頂的結點，並把該結點壓入第二個棧stk2；
    // 將當前結點的左孩子和右孩子先後分別入棧stk；
    // 當所有元素都壓入stk2後，依次彈出stk2的棧頂結點，並訪問之。
    // 第一個棧的入棧順序是：根結點，左孩子和右孩子；於是，壓入第二個棧的順序是：根結點，右孩子和左孩子。因此，彈出的順序就是：左孩子，右孩子和根結點。
    void postOrder2(TreeNode * Root) {

        if (Root == NULL) { return; }

        stack<TreeNode *> stack_TreeNode, stk2;
        stack_TreeNode.push(Root);

        while (!stack_TreeNode.empty()) {

            TreeNode *ptr_TreeNode = stack_TreeNode.top();

            stack_TreeNode.pop();
            stk2.push(ptr_TreeNode);

            if (ptr_TreeNode->left != NULL) { stack_TreeNode.push(ptr_TreeNode->left); }
            if (ptr_TreeNode->right != NULL) { stack_TreeNode.push(ptr_TreeNode->right); }
        }

        while (!stk2.empty()) {
            cout << stk2.top()->var << endl;
            stk2.pop();
        }
    }

    // 另外，二叉樹的後序遍歷的非遞迴實現，也可以只使用一個棧來實現。
    void postOrder2(TreeNode * Root) {

        if (Root == NULL) { return; }

        stack<TreeNode *> stack_TreeNode;
        stack_TreeNode.push(Root);

        TreeNode *prev = NULL;

        while (!stack_TreeNode.empty()) {

            TreeNode *ptr_TreeNode = stack_TreeNode.top();

            if (!prev || prev->left == ptr_TreeNode || prev->right == ptr_TreeNode) { // traverse down
                if (ptr_TreeNode->left) {
                    stack_TreeNode.push(ptr_TreeNode->left);
                } else if (ptr_TreeNode->right) {
                    stack_TreeNode.push(ptr_TreeNode->right);
                }                                    /* else {
                cout <<  ptr_TreeNode ->var << endl;
                stack_TreeNode.pop();
            }
            */
            } else if (ptr_TreeNode->left == prev) { // traverse up from left
                if (ptr_TreeNode->right) { stack_TreeNode.push(ptr_TreeNode->right); }
            }

            /* else if( ptr_TreeNode ->right == prev) { // traverse up from right
                cout <<  ptr_TreeNode ->var << endl;
                stack_TreeNode.pop();
        }
        */
            else {
                cout << ptr_TreeNode->var << endl;
                stack_TreeNode.pop();
            }

            prev = ptr_TreeNode;
        }
    }
}

else if // 二元樹的走訪(Morris 遍歷)
{
    // Morris遍歷
    // Morris遍歷演算法最神奇的地方就是，只需要常數的空間即可在O(n)時間內完成二叉樹的遍歷。
    // O(1)空間進行遍歷困難之處在於在遍歷的子結點的時候如何重新返回其父節點？
    // 在 Morris 遍歷演算法中，通過修改葉子結點的左右空指標來指向其前驅或者後繼結點來實現的。

    // 中序遍歷
    // 如果當前結點pNode的左孩子為空，那麼輸出該結點，並把該結點的右孩子作為當前結點；
    // 如果當前結點pNode的左孩子非空，那麼就找出該結點在中序遍歷中的前驅結點pPre
    // 當第一次訪問該前驅結點pPre時，其右孩子必定為空，那麼就將其右孩子設定為當前結點，
    // 以便根據這個指標返回到當前結點pNode中，並將當前結點pNode設定為其左孩子；
    // 當該前驅結點pPre的右孩子為當前結點，那麼就輸出當前結點，
    // 並把前驅結點的右孩子設定為空（恢復樹的結構），將當前結點更新為當前結點的右孩子
    // 重複以上兩步，直到當前結點為空。

    void inOrder3(TreeNode * root) {

        if (root == NULL) { return; }

        TreeNode *pNode = root;

        while (pNode != NULL) {

            if (pNode->left == NULL) {

                cout << pNode->val << endl;
                pNode = pNode->right;

            } else {

                TreeNode *pPre = pNode->left;

                while (pPre->right != NULL && pPre->right != pNode) {
                    pPre = pPre->right;
                }

                if (pPre->right == NULL) {

                    pPre->right = pNode;
                    pNode       = pNode->left;

                } else {

                    pPre->right = NULL;
                    cout << pNode->val << endl;
                    pNode = pNode->right;
                }
            }
        }
    }

    // 因為只使用了兩個輔助指標，所以空間複雜度為O(1)。
    // 對於時間複雜度，每次遍歷都需要找到其前驅的結點，而尋找前驅結點與樹的高度相關，
    // 那麼直覺上總的時間複雜度為O(nlogn)。其實，並不是每個結點都需要尋找其前驅結點，
    // 只有左子樹非空的結點才需要尋找其前驅，所有結點尋找前驅走過的路的總和至多為一棵樹的結點個數。
    // 因此，整個過程每條邊最多走兩次，一次使定位到該結點，另一次是尋找某個結點的前驅，所以時間複雜度為O(n)。

    // 如以下一棵二叉樹。首先，訪問的是根結點F，其左孩子非空，
    // 所以需要先找到它的前驅結點（尋找路徑為B->D->E），將E的右指標指向F，
    // 然後當前結點為B。依然需要找到B的前驅結點A，將A的右指標指向B，並將當前結點設定為A。
    // 下一步，輸出A，並把當前結點設定為A的右孩子B。之後，會訪問到B的前驅結點A指向B，
    // 那麼令A的右指標為空，繼續遍歷B的右孩子。依次類推。 一棵二叉樹

    // 前序遍歷
    // 與中序遍歷類似，區別僅僅是輸出的順序不同。

    void preOrder3(TreeNode * root) {

        if (root == NULL) { return; }

        TreeNode *pNode = root;

        while (pNode) {

            if (pNode->left == NULL) {

                cout << pNode->val << endl;
                pNode = pNode->right;

            } else {

                TreeNode *pPre = pNode->left;

                while (pPre->right != NULL && pPre->right != pNode) {
                    pPre = pPre->right;
                }

                if (pPre->right == NULL) {

                    pPre->right = pNode;
                    cout << pNode->val << endl;
                    pNode = pNode->left;

                } else {

                    pPre->right = NULL;
                    pNode       = pNode->right;
                }
            }
        }
    }

    // 後序遍歷
    // 先建立一個臨時結點dummy，並令其左孩子為根結點root，將當前結點設定為dummy；
    // 如果當前結點的左孩子為空，則將其右孩子作為當前結點；
    // 如果當前結點的左孩子不為空，則找到其在中序遍歷中的前驅結點
    // 如果前驅結點的右孩子為空，將它的右孩子設定為當前結點，將當前結點更新為當前結點的左孩子；
    // 如果前驅結點的右孩子為當前結點，倒序輸出從當前結點的左孩子到該前驅結點這條路徑上所有的結點。
    // 將前驅結點的右孩子設定為空，將當前結點更新為當前結點的右孩子。
    // 重複以上過程，直到當前結點為空。
    void reverse(TreeNode * p1, TreeNode * p2) {

        if (p1 == p2) { return; }

        TreeNode *x = p1;
        TreeNode *y = p1->right;

        while (true) {
            TreeNode *temp = y->right;
            y->right       = x;
            x              = y;
            y              = temp;

            if (x == p2) { break; }
        }
    }

    void printReverse(TreeNode * p1, TreeNode * p2) {

        reverse(p1, p2);

        TreeNode *pNode = p2;

        while (true) {
            cout << pNode->val << endl;
            if (pNode == p1) { break; }
            pNode = pNode->right;
        }

        reverse(p2, p1);
    }

    void postOrder3(TreeNode * root) {

        if (root == NULL) { return; }

        TreeNode *dummy = new TreeNode(-1);
        dummy->left     = root;
        TreeNode *pNode = dummy;

        while (pNode != NULL) {

            if (pNode->left == NULL) {

                pNode = pNode->right;

            } else {

                TreeNode *pPrev = pNode->left;

                while (pPrev->right != NULL &&
                       pPrev->right != pNode) {
                    pPrev = pPrev->right;
                }

                if (pPrev->right == NULL) {

                    pPrev->right = pNode;
                    pNode        = pNode->left;

                } else {

                    printReverse(pNode->left, pPrev);
                    pPrev->right = NULL;
                    pNode        = pNode->right;
                }
            }
        }
    }
}