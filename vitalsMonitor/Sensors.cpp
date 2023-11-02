#include <iostream>
#include "Sensors.h"


#ifdef __linux__
// Linux Code
#elif _WIN32
	Sensors::Sensors(bool isHRM, bool isOxSat, bool isRR, bool conType[]) {
		init_BLE();
	};

	Sensors::~Sensors()
	{
	}

	void Sensors::init_BLE() {
		ready = true;
	}

	short int Sensors::get_RawHRData() {
		return _rawData[0];
	}

	short int Sensors::get_RawOxSatData() {
		return _rawData[1];
	}
	short int Sensors::get_RawRRData() {
		return _rawData[2];
	}
	std::vector<float> Sensors::get_SampleData() {
		return { -0.00162229,0.00245922,0.00017747,-0.01512071,-0.03885242,-0.06341399,-0.07121147,-0.06777475,-0.06747025,-0.069192,-0.08356939,-0.09505556,-0.1035412,-0.10699773,-0.10799148,-0.10734607,-0.10701723,-0.1071306,-0.10699361,-0.11372489,-0.11783015,-0.11743582,-0.11212912,-0.10043244,-0.08862785,-0.08295276,-0.07121293,-0.06390846,-0.05788992,-0.05770024,-0.06242823,-0.06222765,-0.05759527,-0.051475,-0.0463383,-0.03873285,-0.02741932,-0.01041667,0.00437694,0.00715698,0.00138787,-0.0028774,0.00049757,0.01352766,0.02438907,0.02996443,0.02519255,0.01872376,0.01295253,0.00731403,0.01163947,0.01457477,0.01770113,0.02122813,0.01304667,0.00621292,0.00877059,0.00800685,0.01704746,0.01865981,0.01343122,0.01141831,0.0107162,0.01089597,0.02330973,0.03029587,0.03735998,0.0344796,0.02525684,0.01353914,0.01493657,0.0193853,0.02828956,0.03129643,0.02586322,0.02337563,0.02513719,0.03105752,0.03895164,0.0365607,0.03739329,0.03381674,0.0301001,0.03235164,0.02248468,0.02858975,0.03124196,0.03260808,0.03652075,0.02268318,0.01282447,0.00655645,0.00216714,0.00436976,-0.0022013,0.00169401,0.01092004,0.02161853,0.03331259,0.01921915,-0.00140367,-0.02728668,-0.05475994,-0.06710354,-0.0716728,-0.07071392,-0.06254966,-0.04875155,-0.01806039,0.03461687,0.11274574,0.23019969,0.36899593,0.52467668,0.65138477,0.7219975,0.73032188,0.66743934,0.56345189,0.45377263,0.35678488,0.30496088,0.28781527,0.273624,0.25532702,0.21173359,0.17288283,0.14343496,0.11735415,0.08191352,0.03858021,-0.01286232,-0.05314676,-0.07844029,-0.09092254,-0.10061739,-0.11265468,-0.12399308,-0.13127574,-0.13100477,-0.13111395,-0.1291742,-0.12836164,-0.1293876,-0.12510896,-0.12256482,-0.12285117,-0.12913392,-0.13908012,-0.14846095,-0.15278615,-0.15915057,-0.16634557,-0.18304363,-0.20496756,-0.2271426,-0.24330448,-0.24801518,-0.24564432,-0.25409475,-0.28047076,-0.32704499,-0.38093588,-0.42894018,-0.47333878,-0.516653,-0.55578339,-0.59180737,-0.612378,-0.6204282,-0.61961591,-0.61388934,-0.60362113,-0.59065211,-0.57394868,-0.54013366,-0.49705252,-0.4407258,-0.38860059,-0.35803694,-0.33612022,-0.31331745,-0.28361344,-0.22220102,-0.16719584,-0.11388236,-0.07042082,-0.04748197,-0.02757711,-0.00442473,0.01182351,0.03750689,0.05152812,0.05794703,0.05642219,0.05631169,0.05700841,0.06792905,0.07728209,0.08643191,0.08588667,0.07961704,0.0690438,0.06745867,0.06989044,0.0822665,0.08465739,0.08886938,0.090362,0.08867013,0.0889091,0.08842839,0.09062012,0.09623235,0.09739186,0.09135439,0.08346272,0.07827818,0.0822214,0.08778933,0.09452633,0.09628773,0.10547352,0.1062184,0.10966821,0.1020818,0.09999312,0.09572984,0.09785309,0.09663297,0.10133982,0.09786694,0.09920037,0.10024716,0.10715822,0.11331177,0.11924118,0.11504232,0.1096432,0.09552828,0.08471613,0.07335354,0.06406174,0.06895547,0.07578561,0.079069,0.07849678,0.07472683,0.08509848,0.10010205,0.11424543,0.11267263,0.10539033,0.09618285,0.0840503,0.07379881,0.06624064,0.05968871,0.07522827,0.08522809,0.08925847,0.08285797,0.06655196,0.06082565,0.06661537,0.07295306,0.07914634,0.07367197,0.0625743,0.05650932,0.05630393,0.05755806,0.06111048,0.05473731,0.0475764,0.04472164,0.04633716,0.05493801,0.06200604,0.05458568,0.0492525,0.04278205,0.04984959,0.05938095,0.06308506,0.05672054,0.04006374,0.03100279,0.02301985,0.02538061,0.02735724,0.03053432,0.03475824,0.03423307,0.02990427,0.03648853,0.03427284,0.04171216,0.03769742,0.03624283,0.04037723,0.04609594,0.04962946,0.0469734,0.03230514,0.03034483,0.03244489,0.05209824,0.06693947,0.07321915,0.07116467,0.062678,0.05422837,0.05313984,0.04537081,0.04106016,0.02843787,0.01287907,0.003201,0.00103772,0.00370146,0.00370998,-0.00761061,-0.02318607,-0.03229252,-0.03124153,-0.01883984,-0.00539163,0.00297325,0.00947671,0.01296198,0.01910689,0.0242656,0.02721252,0.02914243,0.02503062,0.02220581,0.02570986,0.03182661,0.04190565,0.0506934,0.05646612,0.05965442,0.05716885,0.05475246,0.05308951,0.05319716,0.0539839,0.05871102,0.05355056,0.04944031,0.02576754,-0.0033072,-0.01051163,-0.02026122,-0.04730964,-0.09971691,-0.19433445,-0.2356355,-0.21241857,-0.12292335,0.00817689,0.10300868,0.14211784,0.14671919,0.12032618,0.10468499,0.09845552,0.09294014,0.08140297,0.06131815,0.03963173,0.02608818,0.0278564,0.03034792,0.02985136,0.02716751,0.01935864,0.01689399,0.02102055,0.02004957,0.01862038,0.01915054,0.02212509,0.03628164,0.03996979,0.03477923,0.02043896,0.00749709,0.00122164,0.00951947,0.01812499,0.02739895,0.02159521,0.00633964,-0.00367904,-0.00187433,0.00337737,0.00605944,-0.00182345,-0.01291545,-0.01402269,-0.00973554,-0.00213081,0.00265914,0.00171611,-0.00134344,-0.00467287,-0.01002754,-0.01925819,-0.03165603,-0.04198895,-0.05541047,-0.0604152,-0.06776318,-0.07747436,-0.08602076,-0.10076617,-0.110368,-0.11697403,-0.11485252,-0.10379206,-0.09173193,-0.08419551,-0.08455792,-0.08359951,-0.07258605,-0.06498697,-0.05215993,-0.04958489,-0.04516306,-0.03453888,-0.01988918,-0.00349613,0.01158721,0.01961862,0.02519832,0.02618554,0.02755069,0.02830443,0.03025967,0.02819103,0.02465525,0.02848939,0.03263318,0.04181579,0.04205435,0.03558776,0.02281386,0.00928027,-0.00024468,0.0007706,-0.00356952,0.00100718,-0.0041972,-0.00353946,0.00087661,0.00500559,0.00873138,0.00900748,-0.00260796,-0.00110938,-0.01840951,-0.04960954,-0.10761044,-0.19004357,-0.27167699,-0.34022748,-0.40770748,-0.44627929,-0.53723609,-0.64266497,-0.77672648,-0.8938663,-0.91989106,-0.8529774,-0.69687402,-0.46112159,-0.25054175,-0.05962685,0.05770296,0.10325065,0.12904099,0.13949881,0.15483662,0.1701223,0.17341532,0.17788655,0.18473108,0.19014096,0.19301419,0.19968252,0.20816241,0.21512879,0.22533076,0.22448227,0.23197699,0.23368403,0.23983759,0.24047656,0.23562413,0.22889076,0.22610478,0.22366083,0.23150663,0.23267503,0.23218194,0.22411367,0.21894312,0.21897949,0.22338763,0.23075125,0.22615878,0.22336775,0.21915671,0.21800828,0.22335975,0.22277753,0.22332101,0.23310958,0.24460387,0.26783267,0.28584456,0.29559848,0.29529786,0.28296611,0.27080956,0.26299429,0.25170523,0.24298295,0.22564435,0.21022715,0.1966331,0.18625404,0.17071681,0.15154451,0.13272768,0.11672679,0.11443777,0.10951787,0.10667287,0.09634214,0.08028492,0.06306846,0.04829911,0.03950783,0.0381046,0.03402588,0.02842849,0.01452201,0.00161933,-0.00668804,-0.01099889,-0.01355312,-0.01845524,-0.02898936,-0.03651958,-0.04422373,-0.05011402,-0.0575937,-0.06290811,-0.06105753,-0.05201361,-0.05005949,-0.04768157,-0.06116229,-0.05939789,-0.05838865,-0.05351635,-0.04679482,-0.05225998,-0.06158874,-0.06094293,-0.06377573,-0.05421343,-0.05154049,-0.05937527,-0.06938715,-0.07560335,-0.07591691,-0.06922449,-0.06669571,-0.07379408,-0.0777626,-0.08066636,-0.08041264,-0.07280125,-0.06471194,-0.05704776,-0.05301311,-0.05083555,-0.04690647,-0.03477218,-0.02708888,-0.02176847,-0.02199861,-0.023633,-0.02089083,-0.01669114,-0.01328741,-0.0104137,-0.01080056,-0.01302065,-0.02008381,-0.02012499,-0.01243136,-0.00215703,0.00660167,-0.00119849,-0.0122555,-0.01581432,-0.01312252,-0.00152232,0.00215106,-0.00415482,-0.00523548,-0.00202456,0.00909288,0.01939182,0.01860731,0.01358019,0.01122485,0.01285157,0.01922361,0.02092665,0.02010807,0.01841745,0.01890692,0.01875395,0.01937295,0.01585795,0.01464126,0.01279767,0.01370512,0.00863285,0.00257402,-0.00549931,-0.00853095,-0.0049332,-0.00263101,-0.00185438,-0.00345382,-0.00321836,0.00203741,0.00810967,0.00878297,0.00858425,0.00460053,0.00620286,0.0084439,0.00807079,0.00733642,0.00377115,0.00349225,0.00378926,0.00484476,0.00296112,0.00514117,0.00524288,0.01303438,0.012801,0.01244311,0.00976741,0.00987341,0.01463045,0.02155306,0.01728291,0.01360178,0.00744674,0.0102023,0.01477132,0.01588496,0.01063505,0.01177924,0.01011436,0.01256922,0.00896259,-0.00161019,-0.00366123,-0.00178328,0.00685863,0.01589831,0.01554227,0.01714676,0.01583044,0.0066913,-0.00128907,-0.0163591,-0.01848654,-0.01618832,-0.00925368,-0.00377865,-0.00473835,-0.00971315,-0.00860966,-0.00837146,-0.00278708,-0.00367242,-0.00987761,-0.01902295,-0.02008094,-0.01563635,-0.00896247,-0.00927381,-0.02303081,-0.03980311,-0.04838107,-0.04279531,-0.0325418,-0.01917841,-0.02083453,-0.02555228,-0.03129093,-0.03322292,-0.01938051,-0.00012163,0.01653859,0.02416968,0.0087416,-0.01676718,-0.04691982,-0.06327592,-0.06676898,-0.05938784,-0.05232646,-0.05067891,-0.04976515,-0.04912251,-0.04171049,-0.0259676,-0.02050242,-0.01535144,-0.02002599,-0.02298131,-0.02177079,-0.01898627,-0.01189078,-0.00800733,0.00491243,0.01786562,0.02658258,0.03249874,0.02622112,0.0246718,0.02550145,0.02208117,0.02346176,0.0169216,0.01446024,0.01675044,0.02057787,0.02509177,0.00205951,-0.04514531,-0.12076062,-0.1963146,-0.22554007,-0.20039643,-0.11773968,-0.00909407,0.07344189,0.12646453,0.13103881,0.11378795,0.08744137,0.05962755,0.04207805,0.02943566,0.02649114,0.03448377,0.03501518,0.0342039,0.0247205,0.01193482,0.00876138,0.00705416,0.00282438,0.00204208,-0.00755106,-0.0114716,0.00185232,0.02347357,0.03792397,0.04126908,0.02315951,0.00907607,0.00997482,0.01292671,0.0158875,0.00834899,-0.00831811,-0.01711935,-0.02292431,-0.02625631,-0.02537472,-0.02062583,-0.01544691,-0.00997315,-0.01329486,-0.01275113,-0.01857625,-0.02221414,-0.02919837,-0.04038486,-0.0479771,-0.0481393,-0.05406371,-0.05501736,-0.06592411,-0.08221693,-0.08538276,-0.08994936,-0.09217663,-0.09790783,-0.1144457,-0.11862858,-0.12437616,-0.12929258,-0.13169074,-0.14646819,-0.14576913,-0.13804407,-0.1237419,-0.09940669,-0.08474221,-0.07157038,-0.06452132,-0.06541853,-0.06482856,-0.06550729,-0.06273595,-0.06414298,-0.06398664,-0.05801996,-0.04571456,-0.02616535,-0.00941774,0.00248569,0.00172286,0.00366326,-0.00027414,0.00053407,0.00411761,0.00304399,0.01009899,0.01063231,0.01018882,0.00234901,-0.00371428,0.00035953,0.01029288,0.01751699,0.02017967,0.00569983,0.00178143,-0.00905302,-0.00680398,-0.00273908,-0.00330014,-0.0015789,-0.00730451,-0.01164377,-0.00466966,0.00515759,0.02443561,0.03603207,0.03116308,0.02464664,0.0062237,0.0030035,0.00671465,0.0120722,0.01694382,0.01058799,0.0003025,-0.00574412,-0.0087659,-0.00783782,-0.00713402,-0.00502304,-0.00554839,-0.00196821,-0.00231532,-0.00579826,-0.00225368,0.0024,0.0142251,0.02399709,0.021786,0.01461472,0.0080012,0.00432837,0.00568665,0.00742244,0.01196667,0.01635174,0.0246513,0.01976298,0.00652375,-0.01614002,-0.04074607,-0.06011115,-0.06718221,-0.064921,-0.0544586,-0.03457745,-0.01086615,0.0299156,0.0844136,0.17509767,0.30169696,0.45517814,0.60290974,0.70671153,0.74262381,0.71357387,0.62452704,0.51884466,0.41354647,0.33715484,0.29994148,0.28071249,0.26333132,0.2394924,0.19705464,0.1634195,0.13573554,0.10915522,0.07683392,0.03369002,-0.01773876,-0.05038864,-0.06580663,-0.07369737,-0.0788867,-0.09247482,-0.10674097,-0.11714319,-0.12677452,-0.12911046,-0.13541485,-0.13888712,-0.14081725,-0.15536472,-0.15857182,-0.16681254,-0.17135289,-0.16888307,-0.17376304,-0.17546771,-0.17782448,-0.19063772,-0.20230986,-0.22272521,-0.23476584,-0.24299985,-0.23712988,-0.23991914,-0.25558272,-0.29806706,-0.34455568,-0.39318082,-0.43201584,-0.47539055,-0.51820534,-0.56532466,-0.59611481,-0.61863017,-0.62253231,-0.6234901,-0.61368036,-0.59933293,-0.58347362,-0.5593071,-0.52433759,-0.4769114,-0.4249832,-0.38269645,-0.35723674,-0.33131409,-0.30121306,-0.25184658,-0.19805999,-0.14259851,-0.09581782,-0.05656458,-0.02935678,-0.00789501,0.01009853,0.03108151,0.04452772,0.06036019,0.06490166,0.06956663,0.07434942,0.0763154,0.07882935,0.08179047,0.07914986,0.07488596,0.06219553 };
	}


#elif __APPLE__
#else

#endif


