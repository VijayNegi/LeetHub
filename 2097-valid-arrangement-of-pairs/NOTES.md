}
}
}
};
cout<<startNodes.size();
for(auto i:startNodes)
//for(int i=0;i<n;++i)
{
visited[i]=true;
int v=1;
dfs(pairs[i][1],visited,v);
//cout<<i<<" "<<result.size()<<endl;
if(result.size()==n-1)
{
result.push_back(pairs[i]);
break;
}
result.clear();
visited[i]=false;
}
reverse(result.begin(),result.end());
return result;
}
};