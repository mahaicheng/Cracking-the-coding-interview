/*************************************************************************
	> 文件名: 4.2.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年12月22日 星期二 22时08分24秒
 ************************************************************************/
//深度优先搜索
//

enum state{ unvisited, visited, visiting }
bool existRoad(Gragh g, Node start, Node end)
{
    for(Node i : g.getNode())
    {
        i.state = unvisited;
    }

    start.state = visiting;

    queue<Node> q;
    q.euqueue(start);
    Node u;
    while(!q.empty())
    {
        u = q.dequeue();
        if(u != null)
        {
            for(Node v : u.getadjacent())
            {
                if(v.state == unvisited)
                {
                    if(v == end)
                        return true;
                    
                    v.state = visiting;
                    q.euqueue(v);
                }
            }
            u.state = visited;
        }
    }
    return false;
}

bool existRoad(Gragh g, Node start, Node end)
{
    for(Node u : g.getNode())
    {
        u.state = unvisited;
    }

    start.state = visiting;
    Node u;
    for(u : start.getadjacent())
    {

        if(u.state == unvisited)
        {
            if(u == end)
                return true;
            u.state = visiting;
            start.state = visited;
            return existRoad(Gragh g, Node u, Node end);
        }
    }
}
