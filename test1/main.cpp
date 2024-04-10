#include "BigInteger.h"
#include "GetBigIntPrime.h"
#include <windows.h>



string GetPrime(int index){

    num_size = 32;
    deque<int> ONE;
    ONE.push_back(1);

    string strprime = "";
    while (true)
	{
        
		deque<int> x;
		x = randnum();

		bool ans = miller_rabin(x);
		if (ans)
		{
			strprime = printDeque(x);
			cout << "  is prime!!!" << endl;
			break;
		}
		else
		{
			index++;
			cout << index << endl;
			printDeque(x);
			cout << "  is not prime!!!" << endl;
		}
	}
    return strprime;
}

int main()
{
    // 生成大素数
    DWORD star_time, end_time;
    // star_time = GetTickCount();

    // // 设置随机数种子
    // srand(time(0));
    // string strp, strq;
    // strp = GetPrime(0);
    // strq = GetPrime(rand());
    // while(strp == strq){
    //     strq = GetPrime(rand());
    // }
    // cout << "p:" <<  strp << endl;
    // cout << "q:" <<  strq << endl;

    // end_time = GetTickCount();
    // cout << "生成两个大素数的时间为：" << (end_time - star_time) << "ms." << endl;


    star_time = GetTickCount();
    // BigInt p("808652830035770595459974721195340901"), q("415924872698612520126277439911"), N, n, a("1"), b("2");
    // BigInt p("1262194944700621114818439519677070592387"), q("1298267295100285267030815140801055111737"), N, n, a("1"), b("2");
    BigInt p("781"), q("797"), N, n, a("1"), b("2");
    // BigInt p(strp), q(strq), N, n, a("1"), b("2");

    BigInt d, e;
    BigInt m, s;
    N = p * q;
    s = gcd(p - a, q - a);
    n = s * ((p - a) / s) * ((q - a) / s);
    // cout<<s<<endl;
    // cout<<(p-a)*(q-a)<<endl;
    cout << "n: " << n << endl;
    cout << "N: " << N << endl;

    cout << "请输入整数e：" << endl;
    cin >> e;
    cout << "gcd(e,n): " << gcd(e, n) << endl;
    if (gcd(e, n).values == "1" && (n - e).flag == true)
    {

        d = mod_inverse(e, n);
        cout << "d：" << d << endl;
        cout << "请输入需要加密的字符：" << endl;
        cin >> m;
        BigInt c = mod_fast(m, e, N);
        cout << "加密：" << c << endl;
        /*end_time = GetTickCount();
    cout << "这个程序运行时间为：" << (end_time - star_time) << "ms." << endl;*/
        cout << "解密：" << mod_fast(c, d, N) << endl;
    }
    else
    {
        cout << "d和N非互素或者非1<e<n！" << endl;
    }
    end_time = GetTickCount();
    cout << "这个程序运行时间为：" << (end_time - star_time) << "ms." << endl;
    system("pause");

    return 0;
    // 10407932194664399081925240327364085538615262247266704805319112350403608059673360298012239441732324184842421613954281007791383566248323464908139906605677320762924129509389220345773183349661583550472959420547689811211693677147548478866962501384438260291732348885311160828538416585028255604666224831890918801847068222203140521026698435488732958028878050869736186900714720710555703168729087
    // 415924872698612520126277439911
}
