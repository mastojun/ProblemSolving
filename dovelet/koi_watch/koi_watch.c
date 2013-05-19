main(h,m,s,d){scanf("%d%d%d%d",&h,&m,&s,&d);s+=d;m+=s/60;printf("%d %d %d",(h+m/60)%24,m%60,s%60);}
