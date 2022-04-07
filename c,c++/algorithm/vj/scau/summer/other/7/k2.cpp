
    ios::sync_with_stdio(0);
    int cnt[3]{};
    int s[3]{};
    fori(i,0,3)cin>>cnt[i];
    fori(i,0,3)cin>>s[i];
    int m = accumulate(cnt,cnt+3,0)/2;
    For(i,1,m)cin>>c[i];
    sort(c+1,c+1+m);
    reverse(c+1,c+1+m);
   // cout<<m<<endl;
    int p1[3]{};
    iota(p1,p1+3,0);
   // fori(i,0,3)cout<<p1[i]<<' ';
   int mx = -1e9+10;
    do{
        vector<pa> v1;//ss num
        int cnt1[3]{};
        fori(i,0,3){
            cnt1[i] = cnt[i];
        }
        //fi
        fori(i,0,3){
            int ind2 = p1[i];
            int ind1 = 0;
            int mi = min(cnt1[ind1],cnt1[ind2]);
            /*
            cout<<"ind1: "<<ind1<<" ind2:"<<ind2<<endl;
            cout<<"cnt1: "<<cnt1[ind1]<<" cnt2:"<<cnt1[ind2]<<endl;
            */
            if(ind1 == ind2) mi = cnt1[ind1]/2;
            cnt1[ind1] -= mi;
            cnt1[ind2] -= mi;
            if(mi)v1.pb({s[ind1]+s[ind2],mi});
            /*
            if(ind1 == 0 && ind2 == 2){
                cout<<  s[ind1]+s[ind2]<<endl;
                cout<<mi<<endl;
            }
            */
        }
        int p2[3]{};
        iota(p2,p2+3,0);
        do{
            int cnt2[3]{};
            fori(i,0,3)cnt2[i] = cnt1[i];
            vector<pa>v2 = v1;
            fori(i,0,3){
                int ind2 = p2[i];
                int ind1 = 1;
                int mi = min(cnt2[ind1],cnt2[ind2]);
                if(ind1 == ind2) mi = cnt2[ind1]/2;
                cnt2[ind1] -= mi;
                cnt2[ind2] -= mi;
                if(mi)v2.pb({s[ind1]+s[ind2],mi});
            }
            fori(i,0,3){
                int ind2 = p2[i];
                int ind1 = 2;
               /*
                cout<<"ind1: "<<ind1<<" ind2:"<<ind2<<endl;
                cout<<"cnt1: "<<cnt2[ind1]<<" cnt2:"<<cnt2[ind2]<<endl;
                */
                int mi = min(cnt2[ind1],cnt2[ind2]);
                if(ind1 == ind2) mi = cnt2[ind1]/2;
                cnt2[ind1] -= mi;
                cnt2[ind2] -= mi;
                if(mi)v2.pb({s[ind1]+s[ind2],mi});
            }
            sort(v2.begin(),v2.end());
            int j = 0;
            int tmp = 1e9+10;
            For(i,1,m){
                tmp = min(tmp,c[i]*v2[j].ss);
                v2[j].num--;
                if(v2[j].num == 0)j ++;
            }
            mx = max(mx,tmp);
        }while(next_permutation(p2,p2+3));
        //se
        //third
    }while(next_permutation(p1,p1+3));
    cout<<mx<<endl;
    return 0;
}
/*
3 1 0
40 60 90
18 20
*/
/*
7 0 7
5 10 500
1 1 1 1 1 1 1

0 0 2
10 10 10
10
*/
