//Orthogonal List十字链表
//十字链表是有向图的优化存储结构，把邻接表和逆邻接表相结合

//顶点表
//data firstin firstout
//firstin出边表头指针 firstout入边表头指针

//边表
//tailvex headvex headlink taillink
//tailvex表示弧起点在顶点表中的下标
//headvex表示弧终点在顶点表中的下标
//headlink表示入边表指针域，指向终点相同的下一条边
//taillink表示边表指针域，指向起点相同的下一条边

//十字链表的好处就是因为把邻接表和逆邻接表整合在了一起，
//这样既容易找到以Vi为尾的弧，也容易找到以Vi为头的弧，
//因而容易求得顶点的出度和入度。
//而且它除了结构复杂一点外，其实创建图算法的时间复杂度是和邻接表相同的，
//因此，在有向图的应用中，十字链表是非常好的数据结构模型