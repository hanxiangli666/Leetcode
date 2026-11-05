# 中文站历史解法迁移记录

迁移日期：2026-11-05（America/New_York）。

迁移范围：中文站历史仓库中已实现的 **38 道普通题**。美国站正式 Accepted：**38/38**。

复核账号：`Hanxiang_LI`。美国站逐题查询的 38 个 `question.status` 均为 `ac`，并已保存 38 个独立的正式 Accepted 提交编号。

这批提交用于迁移以前完成的成果。本轮重新练习仍从 **0 题**开始，允许重新练习已经迁移的题目。

每份美国站提交代码都加入中文迁移注释及中文站原题链接。除注释外，提交区中的算法与原仓库逐字一致。

本地验证：38 道题共 **113 组用例**。第 138 题通过同目录 `test_local.py` 编译 C++17 并验证深拷贝；其余题目使用 `leetgo test <题号> --local`。

所有标为 Accepted 的行都先通过美国站远程 Run，再正式提交，并通过账号的 Accepted 提交记录核对提交编号。

| 题号 | 美国站解法 | 中文站原解法 | 本地用例 | 美国站正式提交 |
| --- | --- | --- | --- | --- |
| 1 | [two sum](cpp/0001.two-sum/solution.cpp) | [原解法](../cpp/0001.two-sum/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190345773/) |
| 2 | [add two numbers](cpp/0002.add-two-numbers/solution.cpp) | [原解法](../cpp/0002.add-two-numbers/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190346101/) |
| 3 | [longest substring without repeating characters](cpp/0003.longest-substring-without-repeating-characters/solution.cpp) | [原解法](../cpp/0003.longest-substring-without-repeating-characters/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190346162/) |
| 21 | [merge two sorted lists](cpp/0021.merge-two-sorted-lists/solution.cpp) | [原解法](../cpp/0021.merge-two-sorted-lists/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190346225/) |
| 23 | [merge k sorted lists](cpp/0023.merge-k-sorted-lists/solution.cpp) | [原解法](../cpp/0023.merge-k-sorted-lists/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190346300/) |
| 24 | [swap nodes in pairs](cpp/0024.swap-nodes-in-pairs/solution.cpp) | [原解法](../cpp/0024.swap-nodes-in-pairs/solution.cpp) | 4/4 | [Accepted](https://leetcode.com/submissions/detail/2190346353/) |
| 25 | [reverse nodes in k group](cpp/0025.reverse-nodes-in-k-group/solution.cpp) | [原解法](../cpp/0025.reverse-nodes-in-k-group/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190346458/) |
| 26 | [remove duplicates from sorted array](cpp/0026.remove-duplicates-from-sorted-array/solution.cpp) | [原解法](../cpp/0026.remove-duplicates-from-sorted-array/solution.cpp) | 5/5 | [Accepted](https://leetcode.com/submissions/detail/2190346534/) |
| 27 | [remove element](cpp/0027.remove-element/solution.cpp) | [原解法](../cpp/0027.remove-element/solution.cpp) | 5/5 | [Accepted](https://leetcode.com/submissions/detail/2190346596/) |
| 35 | [search insert position](cpp/0035.search-insert-position/solution.cpp) | [原解法](../cpp/0035.search-insert-position/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190346641/) |
| 49 | [group anagrams](cpp/0049.group-anagrams/solution.cpp) | [原解法](../cpp/0049.group-anagrams/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190346700/) |
| 53 | [maximum subarray](cpp/0053.maximum-subarray/solution.cpp) | [原解法](../cpp/0053.maximum-subarray/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190346752/) |
| 80 | [remove duplicates from sorted array ii](cpp/0080.remove-duplicates-from-sorted-array-ii/solution.cpp) | [原解法](../cpp/0080.remove-duplicates-from-sorted-array-ii/solution.cpp) | 5/5 | [Accepted](https://leetcode.com/submissions/detail/2190346804/) |
| 88 | [merge sorted array](cpp/0088.merge-sorted-array/solution.cpp) | [原解法](../cpp/0088.merge-sorted-array/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190346866/) |
| 94 | [binary tree inorder traversal](cpp/0094.binary-tree-inorder-traversal/solution.cpp) | [原解法](../cpp/0094.binary-tree-inorder-traversal/solution.cpp) | 4/4 | [Accepted](https://leetcode.com/submissions/detail/2190346936/) |
| 98 | [validate binary search tree](cpp/0098.validate-binary-search-tree/solution.cpp) | [原解法](../cpp/0098.validate-binary-search-tree/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190346989/) |
| 100 | [same tree](cpp/0100.same-tree/solution.cpp) | [原解法](../cpp/0100.same-tree/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190347053/) |
| 101 | [symmetric tree](cpp/0101.symmetric-tree/solution.cpp) | [原解法](../cpp/0101.symmetric-tree/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190347112/) |
| 102 | [binary tree level order traversal](cpp/0102.binary-tree-level-order-traversal/solution.cpp) | [原解法](../cpp/0102.binary-tree-level-order-traversal/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190347159/) |
| 104 | [maximum depth of binary tree](cpp/0104.maximum-depth-of-binary-tree/solution.cpp) | [原解法](../cpp/0104.maximum-depth-of-binary-tree/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190347220/) |
| 110 | [balanced binary tree](cpp/0110.balanced-binary-tree/solution.cpp) | [原解法](../cpp/0110.balanced-binary-tree/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190347269/) |
| 121 | [best time to buy and sell stock](cpp/0121.best-time-to-buy-and-sell-stock/solution.cpp) | [原解法](../cpp/0121.best-time-to-buy-and-sell-stock/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190347320/) |
| 128 | [longest consecutive sequence](cpp/0128.longest-consecutive-sequence/solution.cpp) | [原解法](../cpp/0128.longest-consecutive-sequence/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190347382/) |
| 138 | [copy list with random pointer](cpp/0138.copy-list-with-random-pointer/solution.cpp) | [原解法](../cpp/0138.copy-list-with-random-pointer/solution.cpp) | 5/5 | [Accepted](https://leetcode.com/submissions/detail/2190347426/) |
| 148 | [sort list](cpp/0148.sort-list/solution.cpp) | [原解法](../cpp/0148.sort-list/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190347469/) |
| 160 | [intersection of two linked lists](cpp/0160.intersection-of-two-linked-lists/solution.cpp) | [原解法](../cpp/0160.intersection-of-two-linked-lists/solution.cpp) | 5/5 | [Accepted](https://leetcode.com/submissions/detail/2190347523/) |
| 189 | [rotate array](cpp/0189.rotate-array/solution.cpp) | [原解法](../cpp/0189.rotate-array/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190347582/) |
| 199 | [binary tree right side view](cpp/0199.binary-tree-right-side-view/solution.cpp) | [原解法](../cpp/0199.binary-tree-right-side-view/solution.cpp) | 4/4 | [Accepted](https://leetcode.com/submissions/detail/2190347642/) |
| 226 | [invert binary tree](cpp/0226.invert-binary-tree/solution.cpp) | [原解法](../cpp/0226.invert-binary-tree/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190347708/) |
| 230 | [kth smallest element in a bst](cpp/0230.kth-smallest-element-in-a-bst/solution.cpp) | [原解法](../cpp/0230.kth-smallest-element-in-a-bst/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190348302/) |
| 234 | [palindrome linked list](cpp/0234.palindrome-linked-list/solution.cpp) | [原解法](../cpp/0234.palindrome-linked-list/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190348401/) |
| 236 | [lowest common ancestor of a binary tree](cpp/0236.lowest-common-ancestor-of-a-binary-tree/solution.cpp) | [原解法](../cpp/0236.lowest-common-ancestor-of-a-binary-tree/solution.cpp) | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2190348728/) |
| 238 | [product of array except self](cpp/0238.product-of-array-except-self/solution.cpp) | [原解法](../cpp/0238.product-of-array-except-self/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190348844/) |
| 283 | [move zeroes](cpp/0283.move-zeroes/solution.cpp) | [原解法](../cpp/0283.move-zeroes/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190348958/) |
| 543 | [diameter of binary tree](cpp/0543.diameter-of-binary-tree/solution.cpp) | [原解法](../cpp/0543.diameter-of-binary-tree/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190349063/) |
| 704 | [binary search](cpp/0704.binary-search/solution.cpp) | [原解法](../cpp/0704.binary-search/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190349177/) |
| 713 | [subarray product less than k](cpp/0713.subarray-product-less-than-k/solution.cpp) | [原解法](../cpp/0713.subarray-product-less-than-k/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190349274/) |
| 977 | [squares of a sorted array](cpp/0977.squares-of-a-sorted-array/solution.cpp) | [原解法](../cpp/0977.squares-of-a-sorted-array/solution.cpp) | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2190349389/) |

## 本地兼容处理

- 26、27、80：补齐返回数量的预期输出，并保留历史边界用例。
- 49：仅在本地入口对分组和组内元素排序后比较，符合题目允许任意顺序的要求。
- 138：补全本地 Node 类型、随机指针构造和序列化，检查复制节点及随机指针均不引用原链表。leetgo 的普通链表输入转换无法处理本题，改用同目录的本地检查入口。
- 160：按输入下标连接真实的共享尾部，并核对返回的节点地址。
- 236：把输入的节点值映射到原树节点，按本地树序列化格式补齐预期输出。

旧 `cpp/`、`contest/` 和根 `leetgo.yaml` 保持原样；未完成模板和比赛题不在此次迁移范围内。
