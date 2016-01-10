main(n,o,i){
  scanf("%d%d",&n,&o);
  int s = 1000;
  int m = 0;
  for (i = n; i < 201; i++) {
    if (i - (i / n) == o) {
      s = s > i ? i : s;
      m = m < i ? i : m;
    }
  }
  printf("%d %d", s, m);
return 0;
}

