scount= scount <<1;
}
//cout<<"s="<<sum<<"\n";
if(sum <= dividend) {
dividend -=sum;
count += scount;
}
else {
sum = sum>>1;
scount = scount>>1;
dividend -=sum;
count += scount;
//--count;
}
sum = divisor;
scount =1;
}
if(sign)
return -1*count;
return count;
}
};