#include "rsa.h"
#include "ASCIIToStr.h"

int main()
{
	LARGE_INTEGER start, finish, frequency;
	QueryPerformanceFrequency(&frequency);
	double quadpart = (double)frequency.QuadPart;
	double elapsed = 0;

	BN p, q, n, eula, e, d;
	BN p_1, q_1;
	BN plain;//明文
	BN cry;//加密以后
	BN dec;//解密以后

	BN temp1 = { 0 }, temp2 = { 0 }, temp3 = { 0 };//用来测试

	memset(p, 0, BNSIZE);
	memset(q, 0, BNSIZE);
	memset(p_1, 0, BNSIZE);
	memset(q_1, 0, BNSIZE);
	memset(n, 0, BNSIZE);
	memset(eula, 0, BNSIZE);
	memset(e, 0, BNSIZE);
	memset(d, 0, BNSIZE);
	memset(plain, 0, BNSIZE);
	memset(cry, 0, BNSIZE);
	memset(dec, 0, BNSIZE);

	int debug = 0;
	// cout << "debug or not? 1 or 0" << endl;
	// cin >> debug;
	if (debug == 1)
	{
		exclu();
		int bits = 0;
		cout << "how many bits prime do you want?" << endl;
		cin >> bits;
		//int realtime1 = clock();
		QueryPerformanceCounter(&start);
		findprime(p, bits);
		QueryPerformanceCounter(&finish);
		elapsed += (finish.QuadPart - start.QuadPart) / quadpart;
		printf("\nfind a %d bits prime process costs %f ms \n\n", getbits_b(p), elapsed * 1000);
		elapsed = 0;
		//printf("the time is %f seconds\n", );
		cout << "prime p=  " << bn2str(p) << endl;
		cout << "bits of p is    " << getbits_b(p) << endl << endl;
		system("pause");
		return 0;
	}

	if (debug == 2)
	{
		//char pstr[128] = "557615999999792";
		//char qstr[128] = "33825171222171";
		//char nstr[128] = "322331751";
		BN a, b,n,result;
		readbn(a, "myp4.txt");
		readbn(n, "myq4.txt");
		//str2bn(a, pstr);
		//str2bn(b, qstr);
		//str2bn(n, nstr);
		//int judge = 0;
		QueryPerformanceCounter(&start);
		findprime(a, 512);
		QueryPerformanceCounter(&finish);
	//	if (judge)
	//		cout << "a是素数！\n" << endl;
	//	else
	//		cout << "a是合数\n" << endl;
		//cout << "求模幂a^a (mod n)：" << endl;
		//cout << "a是 " << bn2str(a) << endl;
		//cout << "n是 " << bn2str(n) << endl;
		//cout << "n是 " << bn2str(n) << endl;
		
		//for (int i = 0; i < 1; i++)
	//	{
	//		modmul(a, a, n, result);
	//		add(a, a, a);
	//	}
		//modmul(a, a, n, result);
		//QueryPerformanceCounter(&finish);
		elapsed += (finish.QuadPart - start.QuadPart) / quadpart;
		printf("\n对%d个二进制位的数字，花费 %f ms \n\n", getbits_b(a), elapsed * 1000);
		//elapsed = 0;
		//cout << "正确答案是：" << bn2str(result) << endl;

		//memset(result, 0, sizeof(result));
		//
		//int m = getbits_b(n);//模幂里基本上不会出现要模偶数，尤其加解密不太可能出现，认为是+1,R=2^m一定大于n
		//BN RRN = { 0 };//R*R (mod n)
		//BN R = { 0 }, Rp = { 0 }, Np = { 0 };
		//BN a_t = { 1,1 }, b_t;//a=1;n做了二进制展开
		//BN temp1 = { 0 }, temp2 = { 0 };//计算作为result有个清零操作
		//BN Xp = { 0 }, Yp = { 0 };
		//int Bits = (m + 31) / 32;//换算成大的位数
		//int remain = m - 32 * (Bits - 1);//最高的“位”的第[remain-1]位为1，原封不动保留[remain-2]..[0]位就可以
		//R[0] = Bits;
		//R[Bits] = (uint32_t)(1U << (remain - 1));

		//sub(R, n, temp1);//temp1=-N
		//inv_b(temp1, R, Np);
		//modmul(R, R, n, RRN);
		////mont_modexp(a, a, n, result);
		//QueryPerformanceCounter(&start);
		//for (int i = 0; i < 1; i++)
		//{
		//	mont_modmul(a,a,R,n,Np,RRN,result);
		//	add(a, a, a);
		//}
		////modmul(a, a, n, result);
		//QueryPerformanceCounter(&finish);
		//elapsed += (finish.QuadPart - start.QuadPart) / quadpart;
		//printf("\n用蒙哥马利方法模幂花费 %f ms \n\n", elapsed * 1000);
		//cout << "蒙哥马利结果是：" << bn2str(result) << endl;
		////str2bn(n, pstr);
		////str2bn(a,qstr);
		//cout << "求a的逆：" << endl;
		//cout << "a是 " << bn2str(a) << endl;
		//cout << "模数n是 " << bn2str(n) << endl;
		//elapsed = 0;
		//QueryPerformanceCounter(&start);
		//inv_b(a, n, result);
		//QueryPerformanceCounter(&finish);
		//elapsed += (finish.QuadPart - start.QuadPart) / quadpart;
		//printf("\n欧几里得除法求逆花费 %f ms \n\n", elapsed * 1000);
		//cout << "正确逆元是 " << bn2str(result) << endl;
		//elapsed = 0;
		//QueryPerformanceCounter(&start);
		//new_inv(a, n, result);
		//QueryPerformanceCounter(&finish);
		//elapsed += (finish.QuadPart - start.QuadPart) / quadpart;
		//printf("\n另一种方法求逆花费 %f ms \n\n",  elapsed * 1000);
		//
		//cout << "另一种方法逆元是 " << bn2str(result) << endl;
		
		//str2bn(n, pstr);
		//str2bn(eula, qstr);
		//cout << "除法" << endl;
		//readbn(p, "myp4.txt");
		//readbn(q, "myq4.txt");
		//readbn(plain, "plain.txt");
		//readbn(e, "e.txt");
		//uint64_t a = 1UL;
		//printf("%llX\n", a);
		//printf("%llX\n", a<<28);
		//printf("%llX\n", a << 32);
		/*subuint_b(p, 1U, p_1);
		subuint_b(q, 1U, q_1);*/
		//mul(p, q, n);
		//modexp_b(plain, e,n, cry);

		//cout << "p is " << bn2str(p) << endl;
		//cout << "q is " << bn2str(q) << endl;
		//cout << "cryo is " << bn2str(cry) << endl;

		//memset(p, 0, sizeof(p));
		//mul(d, d, p);

		//div_b(p, n, d, eula);
		//cout << "被除数  is " << bn2str(p) << endl;
		//cout << "除数  is " << bn2str(n) << endl;
		//cout << "quo is " << bn2str(d) << endl;
		//cout << "remain is " << bn2str(eula) << endl;
		//unsigned char a = 0x1;
		//unsigned char b = 0x3;
		//unsigned char c = a - b;
		//printf("%X\n", c);
		system("pause");
		return 0;
	}

	//产生p和q，一般情况下是有了的不用自己产生
	char p_path[81] = "myp4.txt";
	char q_path[81] = "myq4.txt";
	char e_path[81] = "e.txt";
	char plain_path[81] = "plain.txt";
	char cipher_path[81] = "cipher.txt";
	char decry_path[81] = "decry.txt";


	int ifgen = 0;//是否产生私钥
	// int ifset = 0;
	// cout << "是否要产生私钥p q? 输入1产生，输入0不产生\n";
	// cin >> ifgen;
	// cout << "是否要改变默认文件路径? 输入1改变，输入0不改变\n";
	// cout << "p 存放在" << p_path << endl;
	// cout << "q 存放在" << q_path << endl;
	// cout << "公钥e存放在" << e_path << endl;
	// cout << "明文存放在" << plain_path << endl;
	// cout << "密文存放在" << cipher_path << endl;
	// cout << "解密文件存放在" << decry_path << endl;
	// cin >> ifset;

	// if (ifset == 1)
	// {
	// 	memset(p_path, 0, sizeof(p_path));
	// 	memset(q_path, 0, sizeof(q_path));
	// 	memset(e_path, 0, sizeof(e_path));
	// 	memset(plain_path, 0, sizeof(plain_path));
	// 	memset(cipher_path, 0, sizeof(cipher_path));
	// 	memset(decry_path, 0, sizeof(decry_path));
	// 	cout << "请输入p存放路径" << endl;
	// 	cin >> p_path;
	// 	cout << "请输入q存放路径" << endl;
	// 	cin >> q_path;
	// 	cout << "请输入e存放路径" << endl;
	// 	cin >> e_path;
	// 	cout << "请输入明文存放路径" << endl;
	// 	cin >> plain_path;
	// 	cout << "请输入密文存放路径" << endl;
	// 	cin >> cipher_path;
	// 	cout << "请输入解密后存放路径" << endl;
	// 	cin >> decry_path;


	// 	cout << "设置以后: " << endl << endl;

	// 	cout << "p 存放在" << p_path << endl;
	// 	cout << "q 存放在" << q_path << endl;
	// 	cout << "e 存放在" << e_path << endl;
	// 	cout << "明文存放在" << plain_path << endl;
	// 	cout << "密文存放在" << cipher_path << endl;
	// 	cout << "解密文件存放在" << decry_path << endl;

	// }
	ifgen = 0; //控制是否产生pq
	if (ifgen == 1)//为1则产生
	{
		exclu();
		genpq(p_path, q_path);
		SETONEBIT_B(e, 10001u);
		writebn(e_path, e);
		readbn(p, p_path);
		readbn(q, q_path);
		readbn(e, e_path);
	}
	else
	{
		readbn(p, p_path);
		readbn(q, q_path);
		readbn(e, e_path);
		cout << "p: " << bn2str(p) << endl;
		cout << "q: " << bn2str(q) << endl;
		cout << "e: " << bn2str(e) << endl;
	}


	//获取p/q


	//计算n
	mul(p, q, n);
	cout << "n: " << bn2str(n) << endl;
	writebn("n.txt", eula);

	subuint_b(p, 1u, p_1);
	cout << "p-1: " << bn2str(p_1) << endl;

	subuint_b(q, 1u, q_1);
	cout << "q-1: " << bn2str(q_1) << endl;

	mul(p_1, q_1, eula);
	cout << "φ(n): " << bn2str(eula) << endl;
	writebn("fn.txt", eula);

	//一般公钥e =65537

	gcd_b(e, eula, temp3);
	if (cmp_b(temp3, ONE_BN) != 0) {
		while (cmp_b(temp3, ONE_BN) != 0)//如果不互素！！！悲剧了
		{
			findprime(e, 17);
			gcd_b(e, eula, temp3);
		}
		cout << "之前公钥e与φ(n)不互素，修改以后的e: " << bn2str(e) << endl;
		writebn("e.txt", e);
	}



	//私钥d  ed =1 mod φ(n)
	inv_b(e, eula, d);
	cout << "d: " << bn2str(d) << endl;
	writebn("d.txt", d);
	//获取明文
	cout << "明文: ";
	printFileContents("resource.txt");
	cout << endl;

	stringToASCII("resource.txt", "plain.txt");
	readbn(plain, plain_path);
	cout << "明文ASCII(HEX): " << bn2str(plain) << endl;
	//加密
	//int time1 = clock();
	elapsed = 0;
	QueryPerformanceCounter(&start);
	modexp_b(plain, e, n, cry);
	QueryPerformanceCounter(&finish);
	elapsed += (finish.QuadPart - start.QuadPart) / quadpart;
	printf("加密耗时%f ms\n", elapsed * 1000);
	cout << "密文ASCII(HEX): " << bn2str(cry) << endl;

	writebn(cipher_path, cry);

	//解密
	//int time2 = clock();
	//modexp_b(cry, d, n, dec);
	elapsed = 0;
	QueryPerformanceCounter(&start);
	crt_b(cry, d, p, q, dec);
	QueryPerformanceCounter(&finish);
	elapsed += (finish.QuadPart - start.QuadPart) / quadpart;
	printf("\n解密密耗时%f ms\n", elapsed * 1000);
	cout << "解密ASCII(HEX): " << bn2str(dec) << endl;
	writebn(decry_path, dec);
	ASCIIToString("decry.txt", "result.txt");


	readbn(temp1, plain_path);
	readbn(temp2, decry_path);

	cout << "明文: ";
	printFileContents("resource.txt");

	cout << endl << "明文ASCII(HEX): " << bn2str(temp1);
	cout << endl << "解密ASCII(HEX): " << bn2str(temp2) << endl;
	
	cout << "解密: ";
	printFileContents("result.txt");

	if (checkresult(plain_path, decry_path) == 1)
		cout << "\n加解密正确！" << endl;
	else
		cout << "\n加解密出现错误！" << endl;
	system("pause");
	return 0;
}
