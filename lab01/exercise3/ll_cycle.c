#include <stddef.h>
#include <assert.h>
#include "ll_cycle.h"

int node_cmp(node *a, node *b){
    // 判断node类型的 a 和 b 是否相等
    // 很重要的一点是：a 和 b 都不能为空，否则会出现段错误。
    // 添加下面两个assert，有助于debug（因为可能出现段错误的地方还有赋值部分）
    assert(a != NULL);    
    assert(b != NULL);
    return (*a).value == (*b).value && (*a).next == (*b).next;
}

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    node *fast, *slow;
    slow = fast = head;

    while (fast != NULL){  
        // 下面这个判断是最关键的，一方面，next不能为空，否则不能给fast赋值（next的next）
        // 另一方面，next的next不能为空，否则待会进行比较时，会出现段错误。
        if ((*fast).next != NULL && (*((*fast).next)).next != NULL) fast = (*((*fast).next)).next;
        else return 0;
        slow = (*slow).next;
        // 上面已经判断过空指针了（形式完全一样），因此对于slow则不用判断。
        if (node_cmp(fast, slow)) return 1;
    }
    return 0;
}   
