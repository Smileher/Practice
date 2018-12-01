//AdjacencyMultilist邻接多重表
//邻接多重表是无向图的优化存储结构，方便对边进行操作

//顶点表
//datafirstedge
//firstedge指向顶点data的序号(下标)与ivex的值相同的边

//边表
//ivexilinkjvexjlink
//ivex和jvex表示某条边的两个顶点序号(顶点表的下标)
//ilink表示指向包含ivex的另一条边，
//ilink指向的边的jvex一定要和它本身的ivex的值相同，如果没有就为NULL
//jlink表示指向包含jvex的另一条边，
//jlink指向的边的jvex一定要和它本身的jvex的值相同，如果没有就为NULL

//邻接多重表与邻接表的差别，仅仅是在于同一条边在邻接表中用两个结点表示，
//而在邻接多重表中只有一个结点，这样对边的操作就方便多了，
//若要删除某图的一个边，只需要改变链接的指向或改成^即可。