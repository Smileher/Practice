//特殊的二叉树
//斜树：一条线不分叉

//满二叉树：叶子结点在同一层

//完全二叉树：从上到下，从左到右按层编号没有空

//从根结点到叶子结点一次经过的结点形成树的一条路径，最长路径的长度为树的深度
//根节点的深度为1

//二叉树的性质
//1.在二叉树的第i层上至多有2^(i-1)个结点(i>=1)
//2.深度为k的二叉树至多有2^k再-1个结点
//3.对于任意一个二叉树T，终端结点数=度为2的结点数+1
//4.具有n个结点的完全二叉树的深度为⌊log2n⌋向下取整-1
//5.如果对一颗有n个结点的完全二叉树(其深度为⌊log2n⌋-1)的结点按层序编号
//对任意一结点i(1<=i<=n)有以下性质：
//①如果i=1，则结点i是二叉树的根，无双亲；如果i>1，则其双亲是结点⌊i/2⌋
//②如果2i>n，则结点i无左孩子(结点i为叶子结点)；否则其左孩子是结点2i
//③如果2i+1>n，则结点i无左孩子；否则其有孩子是结点2i+1