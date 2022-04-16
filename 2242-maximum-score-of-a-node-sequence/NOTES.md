if( nei!=e[0] && nei!=com && scores[nei]>s2)
{
n2 = nei;
s2 = scores[nei];
}
if(s1>=s2)
{
n2=com;
s2 = scores[com];
}
else
{
n1 = com;
s1 = scores[com];
}
}
if(n1>=0 && n2>=0)
{
temp += s1 + s2;
result = max(result,temp);
}
}
return result;
}
};