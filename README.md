# huffman_code
輸入：其格式如下：
n
f1f2…fn
其中n為一正整數，其意義為有n個symbols。f1,…,fn為n個分別以一格空白區隔之非負整數序列。
其中fi代表第i個symbol出現的次數。

輸出：t1t2…tn ,，t1,…,tn為n個分別以一格空白區隔之二元字串序列，
      其中ti代表經Huffman coding後，第i個symbol之二元編碼。
  
輸出格式如下：
n
t1t2…tn
輸入範例：
Input
6
45 13 12 16 9 5
Output
6
0 101 100 111 1101 1100
補充說明：
2. 參數之範圍為n100。fi1000
