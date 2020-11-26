   #include<graphics.h>
 #include<stdio.h> 
                        #include<conio.h> 
#include<dos.h> 
                        #include<stdlib.h> 
#include<ctype.h> 
struct  but3d { int x,y; }b[130]; 
struct opt { int x,y; int 
                        flag; int count; }op[20]; struct dump { int sc; char 
                        *name; }d; struct bullet { int x,y; int flag; }bul; int 
                        colur,bx,by,pixflag,relflag=0,bulhitflag; int 
                        bricount=0,count=4,dx=10,x=400,y=400,bcnt=14,ii,length=50; 
                        int color,incy=0,fallflag=0,dely=2000,padhit=0; int 
                        ry=390,rx=425,dy=10,score=0,xb,yb,k=233,level=1,j,l=20,w=10,but,escflag=0; 
                        char s2[10],s1[10],s[20],ch[1],mx,my,re,open; int 
                        a[130],t,c[130],but; int 
                        hiscore,dieflag=0,hitcount=0,opc =4,oprand,ddx=5,rndop; 
                        char opchar,device,*fname; int ix,iy,ibut; int 
                        mycond,catflag=0; union REGS iregs,oregs; char 
                        restart(); char openscreen(); char selectdevice(); 
                        main() { union REGS i,o; char *p1; d.name = "Kalyan"; 
                        d.sc = 100; start(); initgraphics(); initmouse(); 
                        setcolor(7); border(); open = openscreen(); device = 
                        selectdevice(); hide_m_ptr(); switch(toupper(device)) { 
                        case 'M' : mycond =0;break; case 'K' : mycond =1;break; 
                        } switch(toupper(open)) { case 'D' : dely = 500; break; 
                        case 'N' : dely = 1500; break; case 'E' : dely = 2500; 
                        break; } b[1].x=10+2*l; b[1].y=100; displayscore(); 
                        displaylifes(); LEVEL : settextstyle(0,0,1); 
                        if(level==1) 
{ bcnt=54; mess1(); } if(level==2) { bcnt 
                        =60; mess2(); } if(level==3)
 { bcnt=72; mess3(); } 
                        if(level ==4) 
{ bcnt = 60; mess4(); } if(level==5) { 
                        bcnt=126; mess5(); } 
paddle(x,y,15,length); 
                        mycircle(rx,ry,15,15); settextstyle(1,0,5); setcolor(2); 
                        rectangle(95,195,600,260);
 rectangle(97,197,598,258); 
                        if(mycond==0) 
{ S: setcolor(12); outtextxy(100,200,"Left 
                        Click to Play"); 
                        get_m_button(&ibut,&ix,&iy); if(ibut!=1) 
                        goto S; } else \
{ while(!kbhit()) 
{ 
                        outtextxy(100,200,"Press any Key to Play"); } } 
                        layer(20,190,610,300); settextstyle(0,0,1); 
                        mycircle(rx,ry,0,0); op[1].y = 200; op[1].x = b[25].x; 
                        displayoptions(); setcolor(4); set_m_ptr(100,y); 
                        for(t=1;t<=bcnt;t++ ) { a[t]=0; } /* Loop to monitor 
                        the game */ relflag=0; bulhitflag=1; while( 1) { 
                        settextstyle(1,0,2); setcolor(14); 
                        outtextxy(10,10,"MY-BALL Ver:1.0 Kalyan Srinivas P"); 
                        settextstyle(0,0,1); border(); if(ry>=y-6-4 ) { 
                        if(rx<x+length/6) dx = -30; 
                        if(rx>x+length-length/6) dx = 30; 
                        if(rx<=x+length/3&&rx>=x+length/6) dx=-10; 
                        if(rx>=x+length-length/3&&rx<=x+length-length/6) 
                        dx=10; 
                        if(rx>x+length/3&&rx<x+length-length/3) dx 
                        = 5; /* if(bricount==bcnt-1) padhit++;*/ music(50); dy = 
                        -dy; music(0); } if(ry<=10+6+4 ) {music(50); dy = 5; 
                        music(0); } if(rx>=630-6-10) {music(50); dx = -dx; 
                        music(0); } if(rx<=10+6+4 ) {music(50); dx = -dx; 
                        music(0); } ry= ry+dy; rx= rx+dx; mycircle(rx,ry,15,15); 
                        delay(dely); mycircle(rx,ry,0,0); xb=x;yb=y; /* paddle 
                        movement */ paddle(x,y,0,length); if(relflag==1) { 
                        if(but==1) { pixflag =1; bul.x =x; } } if(pixflag==1) { 
                        bullet ( bul.x,bul.y,0); bul.y = bul.y - 10; 
                        bullet(bul.x,bul.y,14); } check_bullet_hit_brick(); 
                        if(bulhitflag==1||bul.y<=15) { bullet ( 
                        bul.x,bul.y,0); relflag=1; bul.y = y; pixflag=0; } 
                        if(mycond==1) { if(kbhit()) { i.h.ah=0; 
                        int86(22,&i,&o); if(o.h.ah==1) escflag=1; 
                        if(o.h.ah==75) { 
                        music(41);paddle(x,y,0,length);x-=length;paddle(x,y,15,length); 
                        music(0); } if(o.h.ah==77) { 
                        music(41);paddle(x,y,0,length);x+=length;paddle(x,y,15,length); 
                        music(0); } if(o.h.ah==83) { settextstyle(0,0,2); 
                        setcolor(14); rectangle(20,195,600,298); 
                        rectangle(22,197,598,300); setcolor(1); 
                        outtextxy(120,210," ( PAUSE ) " ); outtextxy(50,250," 
                        Press Enter Key to Continue "); while(!kbhit()) ; 
                        layer(20,180,610,310); } } } else { 
                        get_m_button(&but,&x,&y); } if(y>395) y = 
                        395; else if(y<=394) y = 395; if(x-4<10) x=14; 
                        if(x+length+4>630) x=630 - length - 4; 
                        paddle(x,y,15,length); if(but==2 ) escflag =1; 
                        if(fallflag==1) { 
                        layer(op[1].x,op[1].y,op[1].x+15,op[1].y+11); op[1].y += 
                        3; if(op[1].x<=10+6+4 ) {music(50); ddx = -ddx; 
                        music(0); } falloption(op[1].x,op[1].y,opc,opchar); 
                        if(op[1].y >= y-6-5) fallflag=0; } if(op[1].y >= 
                        y-6-4) check_catch_option(); check_died(); 
                        if(bricount==bcnt) { change_level(); goto LEVEL; } 
                        check_died(); 
                        /*if(bricount==bcnt-1&&padhit>3) { 
                        hitcount=1; setfillstyle(1,0); 
                        bar(b[j].x,b[j].y,b[j].x+l+1,b[j].y+w+1); a[j]=1; 
                        change_level(); goto LEVEL; }*/ if(bricount==bcnt) { 
                        change_level(); goto LEVEL; } check_endgame(); 
                        check_hit_brick(); settextstyle(0,0,1); } /* end of 
                        while*/ closegraph(); } /* end of main*/ /* sub 
                        functions to check the progress of the game */ 
                        check_catch_option() { int q; 
                        if(op[1].x>x&&op[1].x<x+length) { 
                        layer(op[1].x,op[1].y,op[1].x+15,op[1].y+11); 
                        paddle(x,y,15,length); op[1].y =200; music(2000); 
                        music(0); if(opc==9) count+=1; else if(opc==3) { 
                        if(dely<=5000) dely += 1000;} else if(opc==7) { 
                        if(length<=180) length+=20; } else if(opc==14) { 
                        paddle(x,y,0,length); if(length>=50) length-= 20; 
                        paddle(x,y,15,length); } else if(opc==4) { 
                        count-=1;catflag=0;relflag=0;} else if(opc==5) {if(dely 
                        >=2000) dely -=1000;} else 
                        if(opc==2&&mycond==0) { catflag=1;} else 
                        if(opc==11&&mycond==0) {relflag 
                        =1;bulhitflag=0;} score+=100; displaylifes(); 
                        displayscore(); } else 
                        if(op[1].x<x||op[1].x>x+length) { 
                        layer(op[1].x,op[1].y,op[1].x+15,op[1].y+11); 
                        paddle(x,y,15,length); op[1].flag =0; op[1].y =200; } 
                        op[1].flag =0; } bullet(int x,int y,int col) { 
                        setcolor(col); ellipse(x,y,0,360,2,6); } check_died() { 
                        if((rx<x||rx>x+length)&&ry >=y-6-4) { 
                        music(100); settextstyle(1,0,3); count=count-1; 
                        catflag=0; relflag=0; displaylifes(); rx=x+25;ry=y-10; 
                        if(x+l+5>= 630 ) rx = 50; music(0); looselife(); 
                        layer(90,200,620,300); } else if(catflag==1) { 
                        if(ry>=y-10) { S: rx=x+20; ry=400-15; y=395; 
                        if(rx>630-length+10) rx = 630-length+2; 
                        mycircle(rx,ry,15,15); if(x-4<10) x=14; 
                        if(x+length+4>630) x=630 - length - 4; 
                        paddle(x,y,15,length); delay(dely); mycircle(rx,ry,0,0); 
                        paddle(x,y,0,length); 
                        get_m_button(&but,&x,&y); if(but!=1) goto S; 
                        } } } check_endgame() { 
                        if(count==0||escflag==1||level>5) { 
                        settextstyle(1,0,5); layer(11,11,628,405); music(40); 
                        setcolor(2); rectangle(95,195,600,298); 
                        rectangle(97,197,598,296); setcolor(14); 
                        outtextxy(100,200," Game Over"); outtextxy(80,240," 
                        Another Game (y / n)"); music(0); re = restart(); if 
                        (re=='Y'||re=='y') { restore_defaults(); main(); } 
                        endscreen(); closegraph(); nosound(); exit(0); } } 
                        change_level() { level+=1; count=count+1; bricount=0; 
                        length = 50; rx = x+5; ry = y-4-6; settextstyle(1,0,5); 
                        setcolor(2); rectangle(12,195,624,260); 
                        rectangle(13,196,623,259); setcolor(14); 
                        outtextxy(40,200," Level is completed"); 
                        outtextxy(40,300,"Press Space to Continue"); getch(); 
                        layer(11,194,629,400); } check_bullet_hit_brick() { 
                        for(j=1;j<=bcnt;j++) { 
                        if((bul.y-3<=b[j].y+w&&bul.y-3>=b[j].y)&&(bul.x>=b[j].x&&bul.x<=b[j].x+l)) 
                        { bulhitflag =0; setfillstyle(1,0); 
                        bar(b[j].x,b[j].y,b[j].x+l+1,b[j].y+w+1); if(a[j]==0) { 
                        music(90); /*dy = -dy;*/ score = score+10; 
                        displayscore(); bricount++; /*b[j].flag=0;*/ music(0); } 
                        a[j]=1; } } } check_hit_brick() { 
                        for(j=1;j<=bcnt;j++) 
                        if(rx>=b[j].x-15&&rx<=b[j].x+l&&ry>=b[j].y-10&&ry<=b[j].y+w) 
                        { setfillstyle(1,0); 
                        bar(b[j].x,b[j].y,b[j].x+l+1,b[j].y+w+1); if(a[j]==0) { 
                        music(90); settextstyle(1,0,3); dy = -dy; score=score + 
                        random(20) + random(10); displayscore(); bricount++; 
                        music(0); oprand = random(9); if(oprand==1) { opc 
                        =9;opchar = '+'; } else if(oprand==2) { opc =3;opchar = 
                        'S'; } else if(oprand==3) { opc =7;opchar = '>'; } 
                        else if(oprand==4){ opc =4;opchar='-'; } else 
                        if(oprand==5) { opc = 14;opchar = '<' ;} else 
                        if(oprand==6) {opc = 5; opchar = 'F' ;} else 
                        if(oprand==7) { opc=2;opchar='C';} else if(oprand==98) { 
                        opc =11;opchar = 'B'; } rndop = random(100); 
                        if(rndop%5==0&&op[1].flag==0) { op[1].flag=1; 
                        fallflag=1; op[1].y =200; op[1].x = 10+random(600); } } 
                        a[j]=1; } } /* function for option falling */ 
                        falloption(int x,int y,int c,char ch) { 
                        button3d(x,y,10,10,c); letter(x,y,10,10,ch,0); 
                        delay(1000); } displayoptions() { 
                        button3d(530,420,10,10,9); letter(530,420,10,10,'+',14); 
                        setcolor(9); outtextxy(540,420," Extra Life"); 
                        button3d(320,460,10,10,3); letter(320,460,10,10,'S',12); 
                        setcolor(3); outtextxy(330,460," Slow Ball"); 
                        button3d(530,460,10,10,5); letter(530,460,10,10,'F',14); 
                        setcolor(5); outtextxy(540,460," Fast Ball"); 
                        button3d(320,420,10,10,7); 
                        letter(320,420,10,10,'>',0); setcolor(7); 
                        outtextxy(330,420," Expand Paddle"); 
                        button3d(530,440,10,10,4); letter(530,440,10,10,'-',15); 
                        setcolor(4); outtextxy(540,440," Kill Paddle"); 
                        button3d(320,440,10,10,14); 
                        letter(320,440,10,10,'<',0); setcolor(14); 
                        outtextxy(330,440," Shrink Paddle" ); 
                        button3d(180,460,10,10,2); letter(180,460,10,10,'C',0); 
                        setcolor(2); outtextxy(190,460," Catch Ball" ); 
                        button3d(180,440,10,10,11); letter(180,440,10,10,'B',0); 
                        setcolor(11); outtextxy(190,440," Shooter" ); } 
                        displaylifes() { settextstyle(1,0,3); setcolor(0); 
                        outtextxy(10,450,s1); sprintf(s1,"Lifes = %d",count); 
                        setcolor(6); outtextxy(10,450,s1); } displayscore() { 
                        settextstyle(1,0,3); setcolor(0); outtextxy(10,420,s); 
                        sprintf(s,"Score = %d",score); setcolor(3); 
                        outtextxy(10,420,s); } /* function to create paddle */ 
                        paddle(int x,int y,int c,int len) { setcolor(c); 
                        rectangle(x,y,x+len,y+5); 
                        rectangle(x+1,y+1,x+len-1,y+4); 
                        rectangle(x+1,y+2,x+len-1,y+3); line(x,y-1,x+len,y-1); 
                        ellipse(x,y+2,0,360,4,3); ellipse(x+len,y+2,0,360,4,3); 
                        } /* functions to create bricks */ mess1() { 
                        for(j=1;j<=21;j++) { if(j%2==0) b[j].y=b[1].y-w; else 
                        b[j].y = b[1].y; button3d(b[j].x,b[j].y,l,w,4); 
                        letter(b[j].x,b[j].y,l,w,3,14); b[j+1].x=b[j].x+l+5; } 
                        b[j].x=b[1].x-l-5; for(j=22;j<=33;j++) { 
                        b[j].y=b[1].y+w; button3d(b[j].x,b[j].y,l,w,4); 
                        letter(b[j].x,b[j].y,l,w,4,14); b[j+1].x=b[j].x+2*l+2*5; 
                        } b[j].x=b[1].x; for(j=34;j<=54;j++) { if(j%2==0) 
                        b[j].y=b[1].y+w+10; else b[j].y = b[1].y+2*w+10; 
                        /*b[j].y=b[1].y+2*w+10;*/
 button3d(b[j].x,b[j].y,l,w,4); 
                        letter(b[j].x,b[j].y,l,w,5,14);
 b[j+1].x=b[j].x+l+5; } } 
                        mess2() 
{ for(j=1;j<=bcnt/4;j++) { b[j].y = 100; 
                        button3d(b[j].x,b[j].y,l,w,7,14); b[j+1].x=b[j].x+l+8; } 
                        b[j].x =100; for(j=bcnt/4+1;j<=bcnt/2;j++) 
{ 
b[j].y = 100+2*w; button3d(b[j].x,b[j].y,l,w,7,14); 
                        b[j+1].x=b[j].x+l+8;
 } b[j].x = 100; 
                        for(j=bcnt/2+1;j<=3*bcnt/4;j++)
 { b[j].y = 100+4*w; 
                        button3d(b[j].x,b[j].y,l,w,7,14); b[j+1].x=b[j].x+l+8; } 
                        b[j].x = 100+2*w; 
for(j=3*bcnt/4+1;j<=bcnt;j++) { 
                        b[j].y = 100+6*w; button3d(b[j].x,b[j].y,l,w,7,14); 
                        b[j+1].x=b[j].x+l+8; } } mess3() { b[j].x=200; 
                        for(j=1;j<=24;j+=1) { if(j%2==0) b[j].y = 30+2*w; 
                        else b[j].y = 30+3*w; button3d(b[j].x,b[j].y,l,w,j); 
                        b[j+1].x=b[j].x+l+2; } b[j].x=b[1].x; 
                        for(j=25;j<=48;j+=1) 
{ if(j%2==0) b[j].y = 30+5*w+2; 
                        else b[j].y = 30+6*w+2; 
                        button3d(b[j].x,b[j].y,l,w,j-24); b[j+1].x=b[j].x+l+2; } 
                        b[j].x=b[1].x; for(j=49;j<=72;j+=1) 
{ if(j%2==0) 
                        b[j].y = 30+8*w+4; else b[j].y = 30+9*w+4; 
                        button3d(b[j].x,b[j].y,l,w,j-48); b[j+1].x=b[j].x+l+2; } 
                        } mess4() { b[j].x =b[1].x; for(j=1;j<=13;j+=1) { 
                        b[j].y = 100 - 1; button3d(b[j].x,b[j].y,l,w,4,14); 
                        b[j+1].x=b[j].x+2*l; } b[j].x=b[1].x+2*w; 
                        for(j=14;j<=25;j+=1) { b[j].y = 100+1*w+3; 
                        button3d(b[j].x,b[j].y,l,w,14,14); b[j+1].x=b[j].x+2*l; 
                        } b[j].x=b[1].x+4*w; for(j=26;j<=36;j+=1) { b[j].y = 
                        100+2*w+6; button3d(b[j].x,b[j].y,l,w,2,14); 
                        b[j+1].x=b[j].x+2*l; } b[j].x=b[1].x+6*w; 
                        for(j=37;j<=46;j+=1) 
{ b[j].y = 100 + 3*w +9; 
                        button3d(b[j].x,b[j].y,l,w,12,14); b[j+1].x=b[j].x+2*l; 
                        } b[j].x = b[1].x + 8*w; for(j=47;j<=55;j++) { b[j].y 
                        = 100 + 4*w+12 ; button3d(b[j].x,b[j].y,l,w,1,14); 
                        b[j+1].x=b[j].x+2*l; } } mess5() 
{ for(j=1;j<=21;j++) 
                        { b[j].y=b[1].y; button3d(b[j].x,b[j].y,l,w,4); 
                        b[j+1].x=b[j].x+l+5;
 } b[j].x=b[1].x; 
                        for(j=21+1;j<=2*21;j++)
 { b[j].y=b[1].y+w+5; 
                        button3d(b[j].x,b[j].y,l,w,4); b[j+1].x=b[j].x+l+5; } 
                        b[j].x=b[1].x; for(j=2*21+1;j<=3*21;j++) { 
                        b[j].y=b[1].y+2*w+10; if(j==52||j==53||j==54)
 { 
                        button3d(b[j].x,b[j].y,l,w,1); } else 
                        button3d(b[j].x,b[j].y,l,w,15); b[j+1].x=b[j].x+l+5; } 
                        b[j].x = b[1].x; for(j=3*21+1;j<=4*21;j++) { 
                        b[j].y=b[1].y+3*w+15; if(j==73||j==74||j==75) 
                        button3d(b[j].x,b[j].y,l,w,1); else 
                        button3d(b[j].x,b[j].y,l,w,15); b[j+1].x=b[j].x+l+5; } 
                        b[j].x=b[1].x; for(j=4*21+1;j<=5*21;j++) { 
                        b[j].y=b[1].y+4*w+20; button3d(b[j].x,b[j].y,l,w,2); 
                        b[j+1].x=b[j].x+l+5; } b[j].x=b[1].x; 
                        for(j=5*21+1;j<=6*21;j++) { b[j].y=b[1].y+5*w+25; 
                        button3d(b[j].x,b[j].y,l,w,2); b[j+1].x=b[j].x+l+5; } } 
                        /* function to clear a layer */ layer(int x1,int y1,int 
                        x2,int y2) { setfillstyle(1,0);
 bar(x1,y1,x2,y2); } /* 
                        functon to produce various sounds */ music(int opt) { 
                        int a; if(opt==0) nosound(); 
for(a=1;a<=opt;a++) { 
                        sound(10+2*opt); delay(10); }
 } char openscreen() { char 
                        reply;
 layer(11,11,629,399);
 settextstyle(0,0,1); 
                        /*setcolor(12); outtextxy(300,0,"DJ-BALL");*/ 
                        settextstyle(4,0,3); setcolor(2); outtextxy(31,11*7," 
                        This Game was developed by Kalyan.P.Srinivas."); 
                        outtextxy(31,14*7," Use Mouse to move your Paddle. You 
                        Will lose a"); 
outtextxy(31,17*7," life when the ball 
                        touch the ground. For each "); outtextxy(31,20*7," brick 
                        you hit you will get 10 points.Level is"); 
                        outtextxy(31,23*7," completed if all the bricks are 
                        over. You will "); outtextxy(31,26*7," score 100 points 
                        for each option you Catch. "); button3d(10,260,620,3); 
                        setcolor(4); settextstyle(1,0,2); outtextxy(31,29*10," 
                        SELECT LEVEL "); button3d(31,330,150,20,7); setcolor(4); 
                        outtextxy(31,330," (D)IFFICULT "); 
                        button3d(31,355,150,20,7); setcolor(4); 
                        outtextxy(31,355," (N)ORMAL "); 
                        button3d(31,380,150,20,7); setcolor(4); 
                        outtextxy(31,380," (E)ASY "); reply = getch(); 
                        restore_defaults(); layer(11,259,629,405); setcolor(4); 
                        restore_defaults(); layer(10,10,629,405); return(reply); 
                        } char selectdevice() { char mycond; setcolor(4); 
                        settextstyle(1,0,2); outtextxy(31,17*7," Select the 
                        Device you want to play with. "); outtextxy(31,20*7," 
                        Press (M) for MOUSE and (K) for KEYBOARD"); 
                        button3d(10,260,620,3); outtextxy(300,29*10,"SELECT 
                        DEVICE "); clk_button(300,330,150,20,7); setcolor(0); 
                        outtextxy(300,330," (M)OUSE "); 
                        clk_button(300,355,150,20,7); setcolor(0); 
                        outtextxy(300,355," (K)EYBOARD "); mycond = getch(); 
                        restore_defaults(); layer(10,10,629,405); 
                        return(mycond); } /* function for option falling */ 
                        fall(int x,int y,int c) { setfillstyle(1 , c); 
                        bar(x,y,x+10,y+10); } /* end screen */ endscreen() { 
                        char sc[20]; layer(0,0,640,480); gette(); d.sc = score; 
                        d.name = fname; sprintf(sc,"%d",d.sc); 
                        button3d(0,0,640,470); 
layer(10,10,630,460); 
                        settextstyle(1,0,3); 
	setcolor(2);
 outtextxy(300,10,"HIGH 
                        SCORE"); 
outtextxy(25,100,d.name); 
                        outtextxy(400,100,sc);
 getch(); layer(0,0,640,470); 
                        button3d(0,0,630,410,7); 
button3d(30,30,580,360,4); 
                        setcolor(2); 
outtextxy(25,100," Thanks for playing this game. "); 
outtextxy(25,130," Mail your comments on this game to me."); 
outtextxy(25,180," pabolukalyan @ yahoomail.com"); 
outtextxy(25,210," mail_to_kalyan2000 @ yahoomail.com "); 
outtextxy(200,250," Good Bye"); 
                        
getch();
 } 

char restart() 
{ 
return(getch()); 
} /* gets a string from keyboard */

 getstring ( char *str, int col ) 
                        
{ 
int i = 0 ; char ch ; /* receive text */ 
while ( 1 ) 
{ 
                        /* receive key */ 
fflush ( stdin ) ; /* if special key like arrow keys etc. are hit, ignore them */ 
if ( ( ch = getch() ) == 0 ) 
{ 
getch() ; 
continue ; 
} /* if Enter key is hit, terminate string */ 
if ( ch == 13 )
 { 
str[i] = '
