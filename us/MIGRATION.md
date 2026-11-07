# 中文站历史解法迁移记录

核对日期：2026-11-07（America/New_York）。

**中国站账号已解 90 道，现已全部迁移并取得美国站正式 Accepted：90/90。** 本记录以账号完整已解清单为范围。

中国站账号：[ren-jian-guan-cha-zhe-z](https://leetcode.cn/u/ren-jian-guan-cha-zhe-z/)；美国站账号：[Hanxiang_LI](https://leetcode.com/u/Hanxiang_LI/)。两站 90 个题目 slug 一一对应，美国站逐题状态已复核为 `ac`，每题均记录独立的正式 Accepted 提交编号。

## 两批迁移与遗漏原因

- 2026-11-05：只处理本地历史仓库已有代码的 38 道。这批结果正确，但当时没有与中国站账号的 90 道完整清单对账，不能称为全部账号成果。
- 2026-11-07：从中国站 Accepted 提交记录补取未纳入第一批的 52 道原代码（其中一道在旧 `contest/` 中也有实现，上次同样漏掉），其中 C++ 35 道、Python 17 道，全部在美国站远程 Run 和正式提交 Accepted。原代码及来源编号另存于 `cn-history/`，保留原编程语言。
- 完整对账：`38 + 52 = 90`，无遗漏、无重复。90 道包括简单 43、中等 42、困难 5 道。

每份迁移提交均注明中文站来源及迁移日期。这些提交用于保留历史成果，迁移数量与本轮重新练习、比赛通过数量分开记录。2026-11-07 双周赛用户自行通过的 2 题不计入这 90 道历史迁移。

本地验证：第一批 113 组，第二批 141 组，共 **254 组**。每题均通过美国站远程 Run，再正式提交，并按 Accepted 提交记录核对编号。机器可读的完整 90 题清单见 [migration-inventory.json](migration-inventory.json)。

## 第一批：本地历史仓库 38 道

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


## 第二批：从账号补取的 52 道

| 题号 | 美国站解法 | 中国站原 Accepted 代码 | 语言 | 本地用例 | 美国站正式提交 |
| --- | --- | --- | --- | --- | --- |
| 11 | [container-with-most-water](python/0011.container-with-most-water/solution.py) | [原代码](../cn-history/python/0011.container-with-most-water/solution.py) / [来源](https://leetcode.cn/submissions/detail/682782673/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191407299/) |
| 15 | [3sum](python/0015.3sum/solution.py) | [原代码](../cn-history/python/0015.3sum/solution.py) / [来源](https://leetcode.cn/submissions/detail/682780343/) | Python3 | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191407583/) |
| 19 | [remove-nth-node-from-end-of-list](cpp/0019.remove-nth-node-from-end-of-list/solution.cpp) | [原代码](../cn-history/cpp/0019.remove-nth-node-from-end-of-list/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/611116956/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191407868/) |
| 20 | [valid-parentheses](cpp/0020.valid-parentheses/solution.cpp) | [原代码](../cn-history/cpp/0020.valid-parentheses/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/704147152/) | C++ | 5/5 | [Accepted](https://leetcode.com/submissions/detail/2191408179/) |
| 42 | [trapping-rain-water](python/0042.trapping-rain-water/solution.py) | [原代码](../cn-history/python/0042.trapping-rain-water/solution.py) / [来源](https://leetcode.cn/submissions/detail/683378276/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191408484/) |
| 50 | [powx-n](cpp/0050.powx-n/solution.cpp) | [原代码](../cn-history/cpp/0050.powx-n/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/668661343/) | C++ | 6/6 | [Accepted](https://leetcode.com/submissions/detail/2191409700/) |
| 54 | [spiral-matrix](python/0054.spiral-matrix/solution.py) | [原代码](../cn-history/python/0054.spiral-matrix/solution.py) / [来源](https://leetcode.cn/submissions/detail/683333603/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191409986/) |
| 61 | [rotate-list](cpp/0061.rotate-list/solution.cpp) | [原代码](../cn-history/cpp/0061.rotate-list/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/611112050/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191410269/) |
| 69 | [sqrtx](cpp/0069.sqrtx/solution.cpp) | [原代码](../cn-history/cpp/0069.sqrtx/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/666043644/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191410555/) |
| 86 | [partition-list](cpp/0086.partition-list/solution.cpp) | [原代码](../cn-history/cpp/0086.partition-list/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/704122710/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191410834/) |
| 92 | [reverse-linked-list-ii](cpp/0092.reverse-linked-list-ii/solution.cpp) | [原代码](../cn-history/cpp/0092.reverse-linked-list-ii/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/611132917/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191411128/) |
| 136 | [single-number](cpp/0136.single-number/solution.cpp) | [原代码](../cn-history/cpp/0136.single-number/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/704144994/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191411417/) |
| 141 | [linked-list-cycle](cpp/0141.linked-list-cycle/solution.cpp) | [原代码](../cn-history/cpp/0141.linked-list-cycle/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/611098328/) | C++ | 5/5 | [Accepted](https://leetcode.com/submissions/detail/2191411724/) |
| 142 | [linked-list-cycle-ii](cpp/0142.linked-list-cycle-ii/solution.cpp) | [原代码](../cn-history/cpp/0142.linked-list-cycle-ii/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/611122905/) | C++ | 5/5 | [Accepted](https://leetcode.com/submissions/detail/2191412049/) |
| 167 | [two-sum-ii-input-array-is-sorted](python/0167.two-sum-ii-input-array-is-sorted/solution.py) | [原代码](../cn-history/python/0167.two-sum-ii-input-array-is-sorted/solution.py) / [来源](https://leetcode.cn/submissions/detail/682779588/) | Python3 | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191412361/) |
| 202 | [happy-number](cpp/0202.happy-number/solution.cpp) | [原代码](../cn-history/cpp/0202.happy-number/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/611104260/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191412632/) |
| 206 | [reverse-linked-list](cpp/0206.reverse-linked-list/solution.cpp) | [原代码](../cn-history/cpp/0206.reverse-linked-list/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/611081446/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191412943/) |
| 209 | [minimum-size-subarray-sum](python/0209.minimum-size-subarray-sum/solution.py) | [原代码](../cn-history/python/0209.minimum-size-subarray-sum/solution.py) / [来源](https://leetcode.cn/submissions/detail/683384687/) | Python3 | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191413265/) |
| 217 | [contains-duplicate](cpp/0217.contains-duplicate/solution.cpp) | [原代码](../cn-history/cpp/0217.contains-duplicate/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/704130150/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191413549/) |
| 268 | [missing-number](python/0268.missing-number/solution.py) | [原代码](../cn-history/python/0268.missing-number/solution.py) / [来源](https://leetcode.cn/submissions/detail/682828733/) | Python3 | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191413860/) |
| 448 | [find-all-numbers-disappeared-in-an-array](python/0448.find-all-numbers-disappeared-in-an-array/solution.py) | [原代码](../cn-history/python/0448.find-all-numbers-disappeared-in-an-array/solution.py) / [来源](https://leetcode.cn/submissions/detail/682959906/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191414174/) |
| 622 | [design-circular-queue](cpp/0622.design-circular-queue/solution.cpp) | [原代码](../cn-history/cpp/0622.design-circular-queue/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/612207290/) | C++ | 1/1 | [Accepted](https://leetcode.com/submissions/detail/2191414483/) |
| 707 | [design-linked-list](cpp/0707.design-linked-list/solution.cpp) | [原代码](../cn-history/cpp/0707.design-linked-list/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/708124069/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191414814/) |
| 709 | [to-lower-case](python/0709.to-lower-case/solution.py) | [原代码](../cn-history/python/0709.to-lower-case/solution.py) / [来源](https://leetcode.cn/submissions/detail/682544990/) | Python3 | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191415133/) |
| 844 | [backspace-string-compare](cpp/0844.backspace-string-compare/solution.cpp) | [原代码](../cn-history/cpp/0844.backspace-string-compare/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/612074293/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191415451/) |
| 946 | [validate-stack-sequences](cpp/0946.validate-stack-sequences/solution.cpp) | [原代码](../cn-history/cpp/0946.validate-stack-sequences/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/612096992/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191415745/) |
| 1266 | [minimum-time-visiting-all-points](python/1266.minimum-time-visiting-all-points/solution.py) | [原代码](../cn-history/python/1266.minimum-time-visiting-all-points/solution.py) / [来源](https://leetcode.cn/submissions/detail/683333465/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191416059/) |
| 1486 | [xor-operation-in-an-array](python/1486.xor-operation-in-an-array/solution.py) | [原代码](../cn-history/python/1486.xor-operation-in-an-array/solution.py) / [来源](https://leetcode.cn/submissions/detail/682544796/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191416344/) |
| 1512 | [number-of-good-pairs](python/1512.number-of-good-pairs/solution.py) | [原代码](../cn-history/python/1512.number-of-good-pairs/solution.py) / [来源](https://leetcode.cn/submissions/detail/682544838/) | Python3 | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191416664/) |
| 1534 | [count-good-triplets](python/1534.count-good-triplets/solution.py) | [原代码](../cn-history/python/1534.count-good-triplets/solution.py) / [来源](https://leetcode.cn/submissions/detail/682544895/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191417045/) |
| 2073 | [time-needed-to-buy-tickets](cpp/2073.time-needed-to-buy-tickets/solution.cpp) | [原代码](../cn-history/cpp/2073.time-needed-to-buy-tickets/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/704149865/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191417336/) |
| 2235 | [add-two-integers](python/2235.add-two-integers/solution.py) | [原代码](../cn-history/python/2235.add-two-integers/solution.py) / [来源](https://leetcode.cn/submissions/detail/682544531/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191417589/) |
| 2236 | [root-equals-sum-of-children](python/2236.root-equals-sum-of-children/solution.py) | [原代码](../cn-history/python/2236.root-equals-sum-of-children/solution.py) / [来源](https://leetcode.cn/submissions/detail/682544753/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191417815/) |
| 2413 | [smallest-even-multiple](python/2413.smallest-even-multiple/solution.py) | [原代码](../cn-history/python/2413.smallest-even-multiple/solution.py) / [来源](https://leetcode.cn/submissions/detail/682544685/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191418043/) |
| 2469 | [convert-the-temperature](python/2469.convert-the-temperature/solution.py) | [原代码](../cn-history/python/2469.convert-the-temperature/solution.py) / [来源](https://leetcode.cn/submissions/detail/682544656/) | Python3 | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191418233/) |
| 3978 | [unique-middle-element](cpp/3978.unique-middle-element/solution.cpp) | [原代码](../cn-history/cpp/3978.unique-middle-element/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/734117325/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191418560/) |
| 3979 | [maximum-valid-pair-sum](cpp/3979.maximum-valid-pair-sum/solution.cpp) | [原代码](../cn-history/cpp/3979.maximum-valid-pair-sum/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/734117613/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191418834/) |
| 3980 | [minimum-operations-to-transform-binary-string](cpp/3980.minimum-operations-to-transform-binary-string/solution.cpp) | [原代码](../cn-history/cpp/3980.minimum-operations-to-transform-binary-string/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/734117840/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191419116/) |
| 3981 | [count-distinct-ways-to-form-target-from-two-strings](cpp/3981.count-distinct-ways-to-form-target-from-two-strings/solution.cpp) | [原代码](../cn-history/cpp/3981.count-distinct-ways-to-form-target-from-two-strings/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/734118047/) | C++ | 4/4 | [Accepted](https://leetcode.com/submissions/detail/2191419414/) |
| 3982 | [sum-of-integers-with-maximum-digit-range](cpp/3982.sum-of-integers-with-maximum-digit-range/solution.cpp) | [原代码](../cn-history/cpp/3982.sum-of-integers-with-maximum-digit-range/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/734135173/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191419680/) |
| 3983 | [subsequence-after-one-replacement](cpp/3983.subsequence-after-one-replacement/solution.cpp) | [原代码](../cn-history/cpp/3983.subsequence-after-one-replacement/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/734138157/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191419921/) |
| 3984 | [divisible-game](cpp/3984.divisible-game/solution.cpp) | [原代码](../cn-history/cpp/3984.divisible-game/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/734142048/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191420148/) |
| 3985 | [palindromic-subarray-sum](cpp/3985.palindromic-subarray-sum/solution.cpp) | [原代码](../cn-history/cpp/3985.palindromic-subarray-sum/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/734143496/) | C++ | 5/5 | [Accepted](https://leetcode.com/submissions/detail/2191420425/) |
| 4014 | [minimum-total-price-after-applying-discounts](cpp/4014.minimum-total-price-after-applying-discounts/solution.cpp) | [原代码](../cn-history/cpp/4014.minimum-total-price-after-applying-discounts/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/741015799/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191420719/) |
| 4015 | [weighted-sum-of-a-tree](cpp/4015.weighted-sum-of-a-tree/solution.cpp) | [原代码](../cn-history/cpp/4015.weighted-sum-of-a-tree/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/741017421/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191420972/) |
| 4016 | [maximum-area-of-two-non-overlapping-square-submatrices](cpp/4016.maximum-area-of-two-non-overlapping-square-submatrices/solution.cpp) | [原代码](../cn-history/cpp/4016.maximum-area-of-two-non-overlapping-square-submatrices/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/741019250/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191421234/) |
| 4024 | [nearest-available-drone](cpp/4024.nearest-available-drone/solution.cpp) | [原代码](../cn-history/cpp/4024.nearest-available-drone/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/742527581/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191421451/) |
| 4025 | [minimize-the-maximum-waiting-time-at-synchronized-traffic-lights](cpp/4025.minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/solution.cpp) | [原代码](../cn-history/cpp/4025.minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/742529504/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191421683/) |
| 4026 | [maximum-gap-between-stations](cpp/4026.maximum-gap-between-stations/solution.cpp) | [原代码](../cn-history/cpp/4026.maximum-gap-between-stations/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/742531103/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191421899/) |
| 4030 | [check-ascii-palindromic](cpp/4030.check-ascii-palindromic/solution.cpp) | [原代码](../cn-history/cpp/4030.check-ascii-palindromic/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/744017759/) | C++ | 2/2 | [Accepted](https://leetcode.com/submissions/detail/2191422120/) |
| 4031 | [find-all-numbers-disappeared-in-an-array-ii](cpp/4031.find-all-numbers-disappeared-in-an-array-ii/solution.cpp) | [原代码](../cn-history/cpp/4031.find-all-numbers-disappeared-in-an-array-ii/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/744019095/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191422335/) |
| 4032 | [longest-subarray-with-at-most-k-distinct-prime-factors](cpp/4032.longest-subarray-with-at-most-k-distinct-prime-factors/solution.cpp) | [原代码](../cn-history/cpp/4032.longest-subarray-with-at-most-k-distinct-prime-factors/solution.cpp) / [来源](https://leetcode.cn/submissions/detail/744021819/) | C++ | 3/3 | [Accepted](https://leetcode.com/submissions/detail/2191422574/) |

## 本地兼容处理

原始代码均保留存档。除第 50 题的精度修正外，提交区保留原算法，仅添加来源注释。

第 50 题：中国站旧解在美国站新增用例 `x=-0.9999999968539456, n=-1669585506` 出现浮点误差（307/309）。美国站副本保留递归快速幂，改为先求正指数幂、最后统一取倒数，并用 `long long` 安全处理最小负整数。原始版本保留在 `cn-history/`；本地加入失败用例和最小负指数边界，共 6 组用例。

其余适配只用于本地验证：

- 26、27、80：补齐返回数量的预期输出，并保留历史边界用例。
- 49：本地对分组和组内元素排序后比较，符合题目允许任意顺序的要求。
- 138：补全 Node、随机指针构造和序列化，并检查深拷贝。使用同目录 `test_local.py`。
- 160：按输入下标连接真实共享尾部，并核对返回的节点地址。
- 236：把输入节点值映射到原树节点，按本地树序列化格式比较。
- 141、142：按 `pos` 将尾节点连接到原链表节点，只向算法传入 `head`。142 额外验证返回节点的身份，使用同目录 `test_local.py` 检查入口下标，避免 leetgo 的普通 ListNode 输出格式限制。两题各含 5 组用例。
- 707：补齐生成模板缺失的预期输出，并增加一组插入、删除及下标边界用例。

旧 `cpp/`、`contest/` 和根 `leetgo.yaml` 保持原样。第 125 题未完成练习模板不属于已迁移题目，也没有在本次提交中暂存。
