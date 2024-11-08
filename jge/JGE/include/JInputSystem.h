#ifndef _JINPUTSYSTEM_H_
#define _JINPUTSYSTEM_H_

#include "JLBFont.h"

extern char input_table[3][9][4];

struct PY_index
	{
		char *PY;
		char *PY_mb;
	};
//"Ć´ŇôĘäČëˇ¨şş×ÖĹĹÁĐąí,Âëąí(mb)"
static char PY_mb_a[] = { "°˘°Ąďš" };
static char PY_mb_ai[] = { "°Ž°Ż°­°Š°Ť°Ľ°§°Ś°Ł°¤°¨°Ş°Ź" };
static char PY_mb_an[] = { "°˛°ą°°°ł°ś°´°¸°ˇ°ľ" };
static char PY_mb_ang[] = { "°š°ş°ť" };
static char PY_mb_ao[] = { "°ź°˝°ž°ż°Ŕ°Á°Â°Ä°Ă" };
static char PY_mb_ba[] = { "°Ë°Í°Č°Ç°É°Ĺ°Ě°Ć°Ę°Î°Ď°Ń°Đ°Ó°Ö°Ő°Ô" };
static char PY_mb_bai[] = { "°×°Ů°Ű°Ř°Ú°Ü°Ý°Ţ" };
static char PY_mb_ban[] = { "°â°ŕ°ă°ä°ß°á°ĺ°ć°ě°ë°é°ç°č°í°ę" };
static char PY_mb_bang[] = { "°î°ď°đ°ó°ń°ň°ö°ř°ô°ů°ő°÷" };
static char PY_mb_bao[] = { "°ü°ú°ű°ýą˘ąŚąĽąŁą¤ą¨ą§ąŞąŤąŠąŹ°ţąĄĆŮ" };
static char PY_mb_bei[] = { "ą°ą­ąŻąŽąąą´ąˇą¸ąłąľąśąťąšąşą˛" };
static char PY_mb_ben[] = { "ąźąžą˝ążşť" };
static char PY_mb_beng[] = { "ąŔąÁąÂąĂąĹąÄ" };
static char PY_mb_bi[] = { "ąĆąÇąČąËąĘąÉąŇąŘąĎąŐąÓąŃąÝąĐąÖąÔąÍą×ąĚąÎąÚąÜąŰ" };
static char PY_mb_bian[] = { "ąßąŕąŢąáąâąĺąăąäąéąćąçąč" };
static char PY_mb_biao[] = { "ąëąęąěąí" };
static char PY_mb_bie[] = { "ąďąîąđąń" };
static char PY_mb_bin[] = { "ąöąňąóąőąôą÷" };
static char PY_mb_bing[] = { "ąůąřąűąüąúąţąý˛˘˛Ą" };
static char PY_mb_bo[] = { "˛Ś˛¨˛Ł˛§˛ą˛¤˛Ľ˛Ž˛ľ˛Ż˛´˛Ş˛Ź˛°˛Š˛ł˛Ť˛­˛˛˛ˇ" };
static char PY_mb_bu[] = { "˛š˛¸˛ś˛ť˛ź˛˝˛Ŕ˛ż˛ş˛ž" };
static char PY_mb_ca[] = { "˛Á" };
static char PY_mb_cai[] = { "˛Â˛Ĺ˛Ä˛Ć˛Ă˛É˛Ę˛Ç˛Č˛Ë˛Ě" };
static char PY_mb_can[] = { "˛Î˛Í˛Đ˛Ď˛Ń˛Ň˛Ó" };
static char PY_mb_cang[] = { "˛Ö˛×˛Ô˛Ő˛Ř" };
static char PY_mb_cao[] = { "˛Ů˛Ú˛Ü˛Ű˛Ý" };
static char PY_mb_ce[] = { "˛á˛ŕ˛Ţ˛â˛ß" };
static char PY_mb_ceng[] = { "˛ă˛äÔř" };
static char PY_mb_cha[] = { "˛ć˛ĺ˛é˛ç˛č˛ë˛ě˛ę˛í˛ď˛îÉ˛" };
static char PY_mb_chai[] = { "˛đ˛ń˛ň" };
static char PY_mb_chan[] = { "˛ô˛ó˛÷˛ö˛ř˛ő˛ú˛ů˛ű˛ü" };
static char PY_mb_chang[] = { "˛ý˛ţłŚł˘łĽłŁł§łĄł¨łŠłŤłŞ" };
static char PY_mb_chao[] = { "ł­łŽłŹł˛łŻł°łąłłł´´Â" };
static char PY_mb_che[] = { "łľłśłšł¸łˇłş" };
static char PY_mb_chen[] = { "łťłžłźłŔłÁł˝łÂłżłÄłĂ" };
static char PY_mb_cheng[] = { "łĆłĹłÉłĘłĐłĎłÇłËłÍłĚłÎłČłŃłŇłÓ" };
static char PY_mb_chi[] = { "łÔłŐłÚłŘłŰłŮłÖłßłŢłÝłÜłâłŕłăłá" };
static char PY_mb_chong[] = { "łäłĺłćłçłč" };
static char PY_mb_chou[] = { "łéłđłńłëłîłíłďłęłěłółňłô" };
static char PY_mb_chu[] = { "łöłőłýłřłüłúłűł÷łů´Ą´˘łţ´Ś´¤´Ľ´ŁĐó" };
static char PY_mb_chuai[] = { "´§" };
static char PY_mb_chuan[] = { "´¨´Š´Ť´Ź´Ş´­´Ž" };
static char PY_mb_chuang[] = { "´ł´Ż´°´˛´´" };
static char PY_mb_chui[] = { "´ľ´ś´š´ˇ´¸" };
static char PY_mb_chun[] = { "´ş´ť´ż´˝´ž´ź´Ŕ" };
static char PY_mb_chuo[] = { "´Á" };
static char PY_mb_ci[] = { "´Ă´Ę´Ä´É´Č´Ç´Ĺ´Ć´Ë´Î´Ě´Í" };
static char PY_mb_cong[] = { "´Ń´Ó´Ň´Đ´Ď´Ô" };
static char PY_mb_cou[] = { "´Ő" };
static char PY_mb_cu[] = { "´Ö´Ů´×´Ř" };
static char PY_mb_cuan[] = { "´Ú´Ü´Ű" };
static char PY_mb_cui[] = { "´Ţ´ß´Ý´ŕ´ă´á´â´ä" };
static char PY_mb_cun[] = { "´ĺ´ć´ç" };
static char PY_mb_cuo[] = { "´ę´č´é´ě´ë´í" };
static char PY_mb_da[] = { "´î´ď´đ´ń´ň´ó" };
static char PY_mb_dai[] = { "´ô´ő´ö´ú´ř´ýľĄ´ů´ű´ü´ţ´÷" };
static char PY_mb_dan[] = { "ľ¤ľĽľŁľ˘ľŚľ¨ľ§ľŠľŤľŽľŻľŹľ­ľ°ľŞ" };
static char PY_mb_dang[] = { "ľąľ˛ľłľ´ľľ" };
static char PY_mb_dao[] = { "ľśľźľşľšľˇľťľ¸ľ˝ľżľÁľŔľž" };
static char PY_mb_de[] = { "ľĂľÂľÄ" };
static char PY_mb_deng[] = { "ľĆľÇľĹľČľËľĘľÉ" };
static char PY_mb_di[] = { "ľÍľĚľÎľŇľĎľĐľÓľŃľŐľ×ľÖľŘľÜľŰľÝľÚľŢľŮ" };
static char PY_mb_dian[] = { "ľŕľáľßľäľăľâľçľčľéľęľćľëľíľěľîľĺ" };
static char PY_mb_diao[] = { "ľóľđľňľďľńľőľöľô" };
static char PY_mb_die[] = { "ľůľřľüľýľţľúľű" };
static char PY_mb_ding[] = { "śĄśŁś˘ś¤śĽśŚśŠś¨ś§" };
static char PY_mb_diu[] = { "śŞ" };
static char PY_mb_dong[] = { "śŤśŹś­śŽśŻśłśąś˛ś°ś´" };
static char PY_mb_dou[] = { "śźśľśˇśśś¸śšśşśť" };
static char PY_mb_du[] = { "ś˝śžśÁśżśŔśÂśÄśĂśĘśĹśÇśČśÉśĆ" };
static char PY_mb_duan[] = { "śËśĚśÎśĎśĐśÍ" };
static char PY_mb_dui[] = { "śŃśÓśÔśŇ" };
static char PY_mb_dun[] = { "śÖśŘśŐś×śÜśŰśŮśÝ" };
static char PY_mb_duo[] = { "śŕśßśáśŢśäśâśăśçśéśćśčśĺ" };
static char PY_mb_e[] = { "śďśíśđśëśěśęśîśňśóśńśöśőśô" };
static char PY_mb_en[] = { "ś÷" };
static char PY_mb_er[] = { "śůśřśűśúśýśüśţˇĄ" };
static char PY_mb_fa[] = { "ˇ˘ˇŚˇĽˇŁˇ§ˇ¤ˇ¨ˇŠ" };
static char PY_mb_fan[] = { "ˇŤˇŹˇ­ˇŞˇ˛ˇŻˇ°ˇłˇŽˇąˇ´ˇľˇ¸ˇşˇšˇśˇˇ" };
static char PY_mb_fang[] = { "ˇ˝ˇťˇźˇŔˇÁˇżˇžˇÂˇĂˇÄˇĹ" };
static char PY_mb_fei[] = { "ˇÉˇÇˇČˇĆˇĘˇËˇĚˇÍˇĎˇĐˇÎˇŃ" };
static char PY_mb_fen[] = { "ˇÖˇÔˇ×ˇŇˇŐˇÓˇŘˇÚˇŮˇŰˇÝˇÜˇŢˇßˇŕ" };
static char PY_mb_feng[] = { "ˇáˇçˇăˇâˇčˇĺˇéˇćˇäˇëˇęˇěˇíˇďˇî" };
static char PY_mb_fo[] = { "ˇđ" };
static char PY_mb_fou[] = { "ˇń" };
static char PY_mb_fu[] = { "ˇňˇôˇőˇó¸Ľˇüˇöˇ÷ˇţˇýˇú¸Ą¸˘ˇű¸¤ˇů¸Łˇř¸§¸Ś¸Ž¸Ť¸Š¸Ş¸¨¸­¸Ż¸¸¸ź¸ś¸ž¸ş¸˝¸Ŕ¸ˇ¸´¸°¸ą¸ľ¸ť¸ł¸ż¸š¸˛" };
static char PY_mb_ga[] = { "¸Â¸Á" };
static char PY_mb_gai[] = { "¸Ă¸Ä¸Ć¸Ç¸Č¸Ĺ" };
static char PY_mb_gan[] = { "¸É¸Ę¸Ë¸Î¸Ě¸Í¸Ń¸Ď¸Ň¸Đ¸Ó" };
static char PY_mb_gang[] = { "¸Ô¸Ő¸Ú¸Ů¸Ř¸×¸Ö¸Ű¸Ü" };
static char PY_mb_gao[] = { "¸Ţ¸á¸ß¸ŕ¸Ý¸â¸ă¸ĺ¸ä¸ć" };
static char PY_mb_ge[] = { "¸ę¸í¸ç¸ě¸ë¸î¸é¸č¸ó¸ď¸ń¸đ¸ô¸ö¸÷¸őżŠ" };
static char PY_mb_gei[] = { "¸ř" };
static char PY_mb_gen[] = { "¸ů¸ú" };
static char PY_mb_geng[] = { "¸ü¸ý¸ű¸ţšĄš˘šŁ" };
static char PY_mb_gong[] = { "š¤š­šŤšŚšĽšŠšŹš§šŞš¨šŽšŻš°š˛šą" };
static char PY_mb_gou[] = { "š´šľšłšˇšśšššşš¸šť" };
static char PY_mb_gu[] = { "šŔšžšĂšÂšÁš˝šźšżšĹšČšÉšÇšĆšÄšĚšĘšËšÍ" };
static char PY_mb_gua[] = { "šĎšÎšĐšŃšŇšÓ" };
static char PY_mb_guai[] = { "šÔšŐšÖ" };
static char PY_mb_guan[] = { "šŘšŰšŮšÚš×šÝšÜšášßšŕšŢ" };
static char PY_mb_guang[] = { "šâšăšä" };
static char PY_mb_gui[] = { "šéšçšęšćšëščšĺšěšîšďšíšôšńšóšđšň" };
static char PY_mb_gun[] = { "šőšöš÷" };
static char PY_mb_guo[] = { "šůšřšúšűšüšý" };
static char PY_mb_ha[] = { "¸ňšţ" };
static char PY_mb_hai[] = { "ş˘şĄşŁşĽş§şŚş¤" };
static char PY_mb_han[] = { "ş¨şŠşŹşŞşŻş­şŽşŤşąş°şşşšşľşˇş´ş¸şśşłş˛" };
static char PY_mb_hang[] = { "şźş˝ĐĐ" };
static char PY_mb_hao[] = { "şÁşŔşżşžşĂşÂşĹşĆşÄ" };
static char PY_mb_he[] = { "şÇşČşĚşĎşÎşÍşÓşŇşËşÉşÔşĐşĘşŘşÖşŐş×" };
static char PY_mb_hei[] = { "şÚşŮ" };
static char PY_mb_hen[] = { "şŰşÜşÝşŢ" };
static char PY_mb_heng[] = { "şŕşßşăşáşâ" };
static char PY_mb_hong[] = { "şäşĺşćşëşěşęşéşçşč" };
static char PY_mb_hou[] = { "şîşíşďşđşóşńşň" };
static char PY_mb_hu[] = { "şőşôşöťĄşüşúşřşţşůş÷şýşűť˘ťŁťĽť§ť¤ťŚ" };
static char PY_mb_hua[] = { "ť¨ťŞťŠťŹťŤťŻťŽť­ť°" };
static char PY_mb_huai[] = { "ťłť˛ť´ťąťľ" };
static char PY_mb_huan[] = { "ťśťšťˇť¸ťşťĂťÂť˝ťťťÁťźťŔťžťż" };
static char PY_mb_huang[] = { "ťÄťĹťĘťËťĆťĚťÍťČťÇťÉťĐťÎťŃťĎ" };
static char PY_mb_hui[] = { "ťŇťÖťÓťÔťŐťŘť×ťÚťÜťăťáťäťćťĺťâťßťŢťŕťÝťŮťŰ" };
static char PY_mb_hun[] = { "ťčťçťéťëťęťě" };
static char PY_mb_huo[] = { "ťíťîťđťďťňťőťńťöťóťô" };
static char PY_mb_ji[] = { "źĽť÷ź˘ťřťúźĄźŚźŁź§ťýťůź¨źŠťűťţťüź¤ź°źŞźłźśź´źŤźąź˛źŹźŻźľź­źŽź¸źşźˇźšźĆźÇźżźÍźËźÉźźźĘźÁźžźČźĂźĚźĹźÄźÂźŔźťź˝˝ĺ" };
static char PY_mb_jia[] = { "źÓźĐźŃźĎźŇźÎźÔźŐź×źÖźŘźŰźÝźÜźŮźŢźÚĐŽ" };
static char PY_mb_jian[] = { "źéźâźáźßźäźçźčźćźŕźăźęźĺźđźóźíźëźńźőźôźěźďźňźîźűźţ˝¨˝¤˝Łźöźú˝Ą˝§˝˘˝Ľ˝Śźůźřźüźý" };
static char PY_mb_jiang[] = { "˝­˝Ş˝Ť˝Ź˝Š˝Ž˝˛˝ą˝°˝Ż˝ł˝ľ˝´" };
static char PY_mb_jiao[] = { "˝ť˝ź˝ż˝˝˝ž˝ş˝ˇ˝š˝ś˝¸˝Ç˝Ć˝Ę˝Č˝Ă˝Ĺ˝Â˝Á˝Ë˝É˝Đ˝Î˝Ď˝Ě˝Ń˝Ížő˝Ŕ" };
static char PY_mb_jie[] = { "˝×˝Ô˝Ó˝Ő˝Ň˝Ö˝Ú˝Ů˝Ü˝ŕ˝á˝Ý˝Ţ˝Ř˝ß˝ă˝â˝é˝ä˝ć˝ě˝ç˝ę˝ë˝č" };
static char PY_mb_jin[] = { "˝í˝ń˝ď˝đ˝ň˝î˝ó˝ö˝ô˝÷˝őžĄž˘˝ü˝ř˝ú˝ţ˝ý˝ű˝ů" };
static char PY_mb_jing[] = { "žŠž­žĽžŁžŞž§žŚžŹž¤žŤž¨žŽžąž°žŻžťžśžˇžşžšž´ž¸žłž˛žľ" };
static char PY_mb_jiong[] = { "žźž˝" };
static char PY_mb_jiu[] = { "žŔžżžžžĹžĂžÄžÁžÂžĆžÉžĘžĚžÎžÇžČžÍžË" };
static char PY_mb_ju[] = { "žÓžĐžŃžÔžŇžĎžÖ˝ŰžŐž×žÚžŮžŘžäžŢžÜžßžćžăžçžĺžÝžŕžâžŰžá" };
static char PY_mb_juan[] = { "žęžčžéžížëžîžě" };
static char PY_mb_jue[] = { "žďžöž÷žńžřžóžňžôžđ" };
static char PY_mb_jun[] = { "žüžýžůžűžúżĄż¤žţżŁżĽż˘" };
static char PY_mb_ka[] = { "ż§żŚż¨" };
static char PY_mb_kai[] = { "żŞżŤż­żŽżŹ" };
static char PY_mb_kan[] = { "ź÷żŻżąż°ż˛żłż´" };
static char PY_mb_kang[] = { "żľżśżˇż¸żşżšżť" };
static char PY_mb_kao[] = { "żźż˝żžżż" };
static char PY_mb_ke[] = { "żŔżÁżÂżĆżĂżĹżÄżÇżČżÉżĘżËżĚżÍżÎ" };
static char PY_mb_ken[] = { "żĎżŃżŇżĐ" };
static char PY_mb_keng[] = { "żÔżÓ" };
static char PY_mb_kong[] = { "żŐż×żÖżŘ" };
static char PY_mb_kou[] = { "żŮżÚżŰżÜ" };
static char PY_mb_ku[] = { "żÝżŢżßżŕżâżăżá" };
static char PY_mb_kua[] = { "żäżĺżćżčżç" };
static char PY_mb_kuai[] = { "żéżěżëżę" };
static char PY_mb_kuan[] = { "żíżî" };
static char PY_mb_kuang[] = { "żďżđżńżöżőżóżňżô" };
static char PY_mb_kui[] = { "ż÷żůżřżúżüżűżýżţŔ˘ŔŁŔĄ" };
static char PY_mb_kun[] = { "Ŕ¤ŔĽŔŚŔ§" };
static char PY_mb_kuo[] = { "ŔŠŔ¨ŔŤŔŞ" };
static char PY_mb_la[] = { "ŔŹŔ­Ŕ˛ŔŽŔ°ŔŻŔą" };
static char PY_mb_lai[] = { "Ŕ´ŔłŔľ" };
static char PY_mb_lan[] = { "ŔźŔšŔ¸ŔˇŔťŔśŔžŔ˝ŔşŔŔŔżŔÂŔÁŔĂŔÄ" };
static char PY_mb_lang[] = { "ŔÉŔÇŔČŔĹŔĆŔĘŔËňë" };
static char PY_mb_lao[] = { "ŔĚŔÍŔÎŔĎŔĐŔŃŔÔŔÓŔŇ" };
static char PY_mb_le[] = { "ŔÖŔŐÁË" };
static char PY_mb_lei[] = { "Ŕ×ŔŘŔÝŔÚŔŮŔÜŔßŔáŔŕŔŰŔŢ" };
static char PY_mb_leng[] = { "ŔâŔăŔä" };
static char PY_mb_li[] = { "ŔĺŔćŔęŔëŔňŔçŔěÁ§ŔčŔéŔńŔîŔďÁ¨ŔíŔđÁŚŔúŔ÷Á˘ŔôŔöŔűŔřÁ¤ŔýÁĽŔţŔóŔőŔůÁŁŔüÁĄ" };
static char PY_mb_lian[] = { "ÁŹÁąÁŻÁ°ÁŤÁŞÁŽÁ­Á˛ÁłÁˇÁśÁľÁ´" };
static char PY_mb_liang[] = { "ÁŠÁźÁšÁşÁ¸ÁťÁ˝ÁÁÁÂÁžÁŔÁż" };
static char PY_mb_liao[] = { "ÁĘÁÉÁĆÁÄÁĹÁČÁÎÁĂÁÇÁÍÁĎÁĚ" };
static char PY_mb_lie[] = { "ÁĐÁÓÁŇÁÔÁŃ" };
static char PY_mb_lin[] = { "ÁÚÁÖÁŮÁÜÁŐÁŘÁ×ÁŰÁÝÁßÁŢÁŕ" };
static char PY_mb_ling[] = { "ÁćÁéÁëÁáÁčÁĺÁęÁçÁâÁăÁäÁěÁîÁí" };
static char PY_mb_liu[] = { "ÁďÁőÁ÷ÁôÁđÁňÁóÁńÁöÁřÁů" };
static char PY_mb_long[] = { "ÁúÁüÁýÁűÂĄÁţÂ¤Â˘ÂŁ" };
static char PY_mb_lou[] = { "ÂŚÂĽÂ§Â¨ÂŞÂŠ" };
static char PY_mb_lu[] = { "ÂśÂŹÂŽÂŤÂŻÂ­ÂąÂ˛Â°ÂłÂ˝ÂźÂ¸ÂšÂťÂľÂˇÂžÂşÂ´" };
static char PY_mb_luan[] = { "ÂĎÂÍÂÎÂĐÂŃÂŇ" };
static char PY_mb_lue[] = { "ÂÓÂÔ" };
static char PY_mb_lun[] = { "ÂŐÂŘÂ×ÂŮÂÚÂÖÂŰ" };
static char PY_mb_luo[] = { "ÂŢÂÜÂßÂŕÂáÂâÂÝÂăÂĺÂçÂćÂä" };
static char PY_mb_lv[] = { "ÂËÂżÂŔÂÂÂĂÂÁÂĹÂĆÂÄÂÉÂÇÂĘÂĚÂČ" };
static char PY_mb_ma[] = { "ÂčÂéÂíÂęÂëÂěÂîÂđÂď" };
static char PY_mb_mai[] = { "ÂńÂňÂőÂóÂôÂö" };
static char PY_mb_man[] = { "ÂůÂřÂ÷ÂúÂüĂĄÂýÂţÂű" };
static char PY_mb_mang[] = { "ĂŚĂ˘Ă¤ĂŁĂ§ĂĽ" };
static char PY_mb_mao[] = { "Ă¨ĂŤĂŹĂŠĂŞĂŽĂ­ĂŻĂ°ĂłĂąĂ˛" };
static char PY_mb_me[] = { "Ă´" };
static char PY_mb_mei[] = { "ĂťĂśĂľĂźĂˇĂ˝ĂşĂ¸ĂšĂżĂŔĂžĂĂĂÁĂÄĂÂ" };
static char PY_mb_men[] = { "ĂĹĂĆĂÇ" };
static char PY_mb_meng[] = { "ĂČĂËĂĘĂÍĂÉĂĚĂĎĂÎ" };
static char PY_mb_mi[] = { "ĂÖĂÔĂŐĂŃĂÓĂŇĂ×ĂĐĂÚĂŮĂŘĂÜĂÝĂŰ" };
static char PY_mb_mian[] = { "ĂßĂŕĂŢĂâĂăĂäĂáĂĺĂć" };
static char PY_mb_miao[] = { "ĂçĂčĂéĂëĂěĂęĂîĂí" };
static char PY_mb_mie[] = { "ĂđĂď" };
static char PY_mb_min[] = { "ĂńĂóĂňĂöĂőĂô" };
static char PY_mb_ming[] = { "ĂűĂ÷ĂůĂúĂřĂü" };
static char PY_mb_miu[] = { "Ăý" };
static char PY_mb_mo[] = { "şŃĂţÄĄÄŁÄ¤ÄŚÄĽÄ˘Ä§Ä¨ÄŠÄ­Ä°ÄŞÄŻÄŽÄŤÄŹ" };
static char PY_mb_mou[] = { "Ä˛ÄąÄł" };
static char PY_mb_mu[] = { "Ä¸ÄśÄľÄˇÄ´ÄžÄżÄÁÄźÄšÄťÄŔÄ˝ÄşÄÂ" };
static char PY_mb_na[] = { "ÄĂÄÄÄÇÄÉÄČÄĆÄĹ" };
static char PY_mb_nai[] = { "ÄËÄĚÄĘÄÎÄÍ" };
static char PY_mb_nan[] = { "ÄĐÄĎÄŃ" };
static char PY_mb_nang[] = { "ÄŇ" };
static char PY_mb_nao[] = { "ÄÓÄŐÄÔÄÖÄ×" };
static char PY_mb_ne[] = { "ÄŘ" };
static char PY_mb_nei[] = { "ÄÚÄŮ" };
static char PY_mb_nen[] = { "ÄŰ" };
static char PY_mb_neng[] = { "ÄÜ" };
static char PY_mb_ni[] = { "ÄÝÄáÄŕÄßÄŢÄăÄâÄćÄäÄçÄĺ" };
static char PY_mb_nian[] = { "ÄéÄęÄíÄěÄëÄîÄč" };
static char PY_mb_niang[] = { "ÄďÄđ" };
static char PY_mb_niao[] = { "ÄńÄň" };
static char PY_mb_nie[] = { "ÄóÄůÄôÄöÄ÷ÄřÄő" };
static char PY_mb_nin[] = { "Äú" };
static char PY_mb_ning[] = { "ÄţĹĄÄüÄűÄýĹ˘" };
static char PY_mb_niu[] = { "ĹŁĹ¤ĹŚĹĽ" };
static char PY_mb_nong[] = { "ĹŠĹ¨Ĺ§ĹŞ" };
static char PY_mb_nu[] = { "ĹŤĹŹĹ­" };
static char PY_mb_nuan[] = { "ĹŻ" };
static char PY_mb_nue[] = { "ĹąĹ°" };
static char PY_mb_nuo[] = { "Ĺ˛ĹľĹłĹ´" };
static char PY_mb_nv[] = { "ĹŽ" };
static char PY_mb_o[] = { "Ĺś" };
static char PY_mb_ou[] = { "ĹˇĹšĹ¸ĹťĹźĹşĹ˝" };
static char PY_mb_pa[] = { "ĹżĹžĹŔ°ŇĹĂĹÁĹÂ" };
static char PY_mb_pai[] = { "ĹÄĹÇĹĹĹĆĹÉĹČ" };
static char PY_mb_pan[] = { "ĹËĹĘĹĚĹÍĹĐĹŃĹÎĹĎ" };
static char PY_mb_pang[] = { "ĹŇĹÓĹÔĹŐĹÖ" };
static char PY_mb_pao[] = { "Ĺ×ĹŮĹŘĹÚĹŰĹÜĹÝ" };
static char PY_mb_pei[] = { "ĹŢĹßĹăĹŕĹâĹáĹćĹĺĹä" };
static char PY_mb_pen[] = { "ĹçĹč" };
static char PY_mb_peng[] = { "ĹęĹéĹëĹóĹíĹďĹđĹîĹôĹěĹńĹňĹőĹö" };
static char PY_mb_pi[] = { "ąŮĹúĹ÷ĹűĹřĹüĹůĆ¤ĹţĆŁĆĄĹýĆ˘ĆĽĆŚĆ¨Ć§ĆŠ" };
static char PY_mb_pian[] = { "ĆŹĆŤĆŞĆ­" };
static char PY_mb_piao[] = { "ĆŻĆŽĆ°Ćą" };
static char PY_mb_pie[] = { "Ć˛Ćł" };
static char PY_mb_pin[] = { "Ć´ĆśĆľĆˇĆ¸" };
static char PY_mb_ping[] = { "ĆšĆ˝ĆŔĆžĆşĆťĆÁĆżĆź" };
static char PY_mb_po[] = { "ĆÂĆĂĆÄĆĹĆČĆĆĆÉĆÇ" };
static char PY_mb_pou[] = { "ĆĘ" };
static char PY_mb_pu[] = { "¸ŹĆÍĆËĆĚĆÎĆĐĆĎĆŃĆÓĆÔĆŇĆÖĆŐĆ×ĆŘ" };
static char PY_mb_qi[] = { "ĆßĆăĆŢĆâĆŕĆÜĆÝĆÚĆŰĆáĆîĆëĆäĆćĆçĆíĆęĆéĆčĆďĆĺĆěĆňĆóĆńĆôĆđĆřĆýĆůĆúĆűĆüĆőĆöĆ÷" };
static char PY_mb_qia[] = { "ĆţÇĄÇ˘" };
static char PY_mb_qian[] = { "Ç§ÇŞÇ¤Ç¨ÇĽÇŁÇŚÇŤÇŠÇ°ÇŽÇŻÇŹÇąÇ­ÇłÇ˛Ç´ÇˇÇľÇśÇ¸" };
static char PY_mb_qiang[] = { "ÇşÇźÇšÇťÇżÇ˝ÇžÇŔ" };
static char PY_mb_qiao[] = { "ÇÄÇĂÇÂÇÁÇÇÇČÇĹÇĆÇÉÇÎÇÍÇĎÇĚÇËÇĘ" };
static char PY_mb_qie[] = { "ÇĐÇŃÇŇÇÓÇÔ" };
static char PY_mb_qin[] = { "Ç×ÇÖÇŐÇŰÇŘÇŮÇÝÇÚÇÜÇŢÇß" };
static char PY_mb_qing[] = { "ÇŕÇâÇáÇăÇäÇĺÇéÇçÇčÇćÇęÇëÇě" };
static char PY_mb_qiong[] = { "ÇîÇí" };
static char PY_mb_qiu[] = { "ÇđÇńÇďÇôÇóÇöÇőÇň" };
static char PY_mb_qu[] = { "ÇřÇúÇýÇüÇůÇűÇ÷ÇţČĄČ˘ČŁČĽČ¤" };
static char PY_mb_quan[] = { "ČŚČŤČ¨ČŞČ­ČŹČŠČ§ČŽČ°ČŻ" };
static char PY_mb_que[] = { "Č˛ČąČłČ´Č¸ČˇČľČś" };
static char PY_mb_qun[] = { "ČšČş" };
static char PY_mb_ran[] = { "ČťČźČ˝Čž" };
static char PY_mb_rang[] = { "ČżČÂČŔČÁČĂ" };
static char PY_mb_rao[] = { "ČÄČĹČĆ" };
static char PY_mb_re[] = { "ČÇČČ" };
static char PY_mb_ren[] = { "ČËČĘČÉČĚČĐČĎČÎČŇČŃČÍ" };
static char PY_mb_reng[] = { "ČÓČÔ" };
static char PY_mb_ri[] = { "ČŐ" };
static char PY_mb_rong[] = { "ČÖČŢČ×ČŮČÝČÜČŘČŰČÚČß" };
static char PY_mb_rou[] = { "ČáČŕČâ" };
static char PY_mb_ru[] = { "ČçČăČĺČćČäČęČéČčČëČě" };
static char PY_mb_ruan[] = { "ČîČí" };
static char PY_mb_rui[] = { "ČďČńČđ" };
static char PY_mb_run[] = { "ČňČó" };
static char PY_mb_ruo[] = { "ČôČő" };
static char PY_mb_sa[] = { "ČöČ÷Čř" };
static char PY_mb_sai[] = { "ČűČůČúČü" };
static char PY_mb_san[] = { "ČýČţÉĄÉ˘" };
static char PY_mb_sang[] = { "ÉŁÉ¤ÉĽ" };
static char PY_mb_sao[] = { "ÉŚÉ§É¨ÉŠ" };
static char PY_mb_se[] = { "ÉŤÉŹÉŞ" };
static char PY_mb_sen[] = { "É­" };
static char PY_mb_seng[] = { "ÉŽ" };
static char PY_mb_sha[] = { "ÉąÉłÉ´É°ÉŻÉľÉśÉˇĎĂ" };
static char PY_mb_shai[] = { "É¸Éš" };
static char PY_mb_shan[] = { "É˝ÉžÉźÉŔÉşÉżÉÁÉÂÉÇÉťÉČÉĆÉÉÉĂÉĹÉÄŐ¤" };
static char PY_mb_shang[] = { "ÉËÉĚÉĘÉŃÉÎÉÍÉĎÉĐ" };
static char PY_mb_shao[] = { "ÉÓÉŇÉŐÉÔÉ×ÉÖÉŘÉŮÉŰÉÜÉÚ" };
static char PY_mb_she[] = { "ÉÝÉŢÉŕÉßÉáÉčÉçÉäÉćÉâÉĺÉă" };
static char PY_mb_shen[] = { "ÉęÉěÉíÉëÉđÉďÉéÉîÉńÉňÉóÉôÉöÉőÉřÉ÷Ę˛" };
static char PY_mb_sheng[] = { "ÉýÉúÉůÉüĘ¤ÉűÉţĘĄĘĽĘ˘ĘŁ" };
static char PY_mb_shi[] = { "ł×ĘŹĘ§ĘŚĘ­ĘŤĘŠĘ¨ĘŞĘŽĘŻĘąĘśĘľĘ°Ę´ĘłĘˇĘ¸ĘšĘźĘťĘşĘżĘĎĘŔĘËĘĐĘžĘ˝ĘÂĘĚĘĆĘÓĘÔĘÎĘŇĘŃĘĂĘÇĘÁĘĘĘĹĘÍĘČĘÄĘÉËĆ" };
static char PY_mb_shou[] = { "ĘŐĘÖĘŘĘ×ĘŮĘÜĘŢĘŰĘÚĘÝ" };
static char PY_mb_shu[] = { "ĘéĘăĘĺĘŕĘâĘáĘçĘčĘćĘäĘßĘëĘęĘěĘîĘňĘđĘóĘńĘíĘďĘőĘůĘřĘöĘ÷ĘúËĄĘüĘýĘűĘţĘô" };
static char PY_mb_shua[] = { "Ë˘ËŁ" };
static char PY_mb_shuai[] = { "ËĽË¤ËŚË§" };
static char PY_mb_shuan[] = { "ËŠË¨" };
static char PY_mb_shuang[] = { "ËŤËŞËŹ" };
static char PY_mb_shui[] = { "Ë­ËŽË°ËŻ" };
static char PY_mb_shun[] = { "ËąËłË´Ë˛" };
static char PY_mb_shuo[] = { "ËľË¸ËˇËś" };
static char PY_mb_si[] = { "ËżËžË˝ËźËšËťËşËŔËČËÄËÂËĹËÇËĂËÁ" };
static char PY_mb_song[] = { "ËÉËËËĘËĎËÎËĐËÍËĚ" };
static char PY_mb_sou[] = { "ËÔËŃËŇËÓ" };
static char PY_mb_su[] = { "ËŐËÖË×ËßËŕËŘËŮËÚËÜËÝËŰ" };
static char PY_mb_suan[] = { "ËáËâËă" };
static char PY_mb_sui[] = { "ËäËçËĺËćËčËęËîËěËéËíËë" };
static char PY_mb_sun[] = { "ËďËđËń" };
static char PY_mb_suo[] = { "ËôËóËňËőËůË÷ËöËř" };
static char PY_mb_ta[] = { "ËýËűËüËúËţĚĄĚ˘Ě¤ĚŁ" };
static char PY_mb_tai[] = { "ĚĽĚ¨Ě§ĚŚĚŤĚ­ĚŹĚŠĚŞ" };
static char PY_mb_tan[] = { "ĚŽĚ°ĚŻĚ˛ĚąĚłĚ¸ĚľĚˇĚśĚ´ĚšĚťĚşĚžĚżĚ˝Ěź" };
static char PY_mb_tang[] = { "ĚŔĚĆĚĂĚÄĚÁĚÂĚĹĚÇĚČĚĘĚÉĚĚĚË" };
static char PY_mb_tao[] = { "ĚÎĚĐĚÍĚĎĚÓĚŇĚŐĚÔĚŃĚÖĚ×" };
static char PY_mb_te[] = { "ĚŘ" };
static char PY_mb_teng[] = { "ĚŰĚÚĚÜĚŮ" };
static char PY_mb_ti[] = { "ĚŢĚÝĚŕĚßĚäĚáĚâĚăĚĺĚëĚęĚéĚčĚćĚç" };
static char PY_mb_tian[] = { "ĚěĚíĚďĚńĚđĚîĚóĚň" };
static char PY_mb_tiao[] = { "ľ÷ĚôĚőĚöĚ÷Ěř" };
static char PY_mb_tie[] = { "ĚůĚúĚű" };
static char PY_mb_ting[] = { "ĚüÍĄĚýĚţÍ˘Í¤ÍĽÍŁÍŚÍ§" };
static char PY_mb_tong[] = { "Í¨ÍŹÍŽÍŠÍ­ÍŻÍŞÍŤÍłÍąÍ°Í˛Í´" };
static char PY_mb_tou[] = { "ÍľÍˇÍśÍ¸" };
static char PY_mb_tu[] = { "ÍšÍşÍťÍźÍ˝ÍżÍžÍŔÍÁÍÂÍĂ" };
static char PY_mb_tuan[] = { "ÍÄÍĹ" };
static char PY_mb_tui[] = { "ÍĆÍÇÍČÍËÍÉÍĘ" };
static char PY_mb_tun[] = { "śÚÍĚÍÍÍÎ" };
static char PY_mb_tuo[] = { "ÍĐÍĎÍŃÍÔÍÓÍŐÍŇÍ×ÍÖÍŘÍŮ" };
static char PY_mb_wa[] = { "ÍŰÍŢÍÚÍÝÍÜÍßÍŕ" };
static char PY_mb_wai[] = { "ÍáÍâ" };
static char PY_mb_wan[] = { "ÍäÍĺÍăÍčÍęÍćÍçÍéÍđÍěÍíÍńÍďÍîÍëÍňÍó" };
static char PY_mb_wang[] = { "ÍôÍöÍőÍřÍůÍ÷ÍýÍüÍúÍű" };
static char PY_mb_wei[] = { "ÎŁÍţÎ˘ÎĄÎŞÎ¤Î§ÎĽÎŚÎ¨ÎŠÎŹÎŤÎ°ÎąÎ˛ÎłÎ­ÎŻÎŽÎŔÎ´ÎťÎśÎˇÎ¸ÎžÎ˝ÎšÎźÎľÎżÎş" };
static char PY_mb_wen[] = { "ÎÂÎÁÎÄÎĆÎĹÎĂÎÇÎÉÎČÎĘ" };
static char PY_mb_weng[] = { "ÎĚÎËÎÍ" };
static char PY_mb_wo[] = { "ÎÎÎĐÎŃÎĎÎŇÎÖÎÔÎŐÎÓ" };
static char PY_mb_wu[] = { "ÎÚÎŰÎŘÎ×ÎÝÎÜÎŮÎŢÎăÎâÎáÎßÎŕÎĺÎçÎéÎëÎäÎęÎćÎčÎđÎńÎěÎďÎóÎňÎîÎí" };
static char PY_mb_xi[] = { "ĎŚĎŤÎ÷ÎüĎŁÎôÎöÎůĎ˘ÎţĎ¤Ď§ĎŠÎřÎúĎŹĎĄĎŞÎýĎ¨ÎőÎűĎĽĎ°ĎŻĎŽĎąĎ­Ď´Ď˛ĎˇĎľĎ¸Ďś" };
static char PY_mb_xia[] = { "ĎşĎšĎťĎŔĎżĎÁĎžĎ˝ĎźĎÂĎĹĎÄ" };
static char PY_mb_xian[] = { "ĎłĎÉĎČĎËĎĆĎÇĎĘĎĐĎŇĎÍĎĚĎŃĎĎĎÎĎÓĎÔĎŐĎŘĎÖĎßĎŢĎÜĎÝĎÚĎŰĎ×ĎŮ" };
static char PY_mb_xiang[] = { "ĎçĎŕĎăĎáĎćĎäĎĺĎâĎęĎéĎčĎíĎěĎëĎňĎďĎîĎóĎńĎđ" };
static char PY_mb_xiao[] = { "ĎüĎűĎôĎőĎúĎöĎůĎýĐĄĎţĐ˘Đ¤ĎřĐ§ĐŁĐŚĐĽ" };
static char PY_mb_xie[] = { "ĐŠĐ¨ĐŞĐŤĐ­Đ°Đ˛ĐąĐłĐŻĐŹĐ´ĐšĐşĐśĐźĐľĐťĐ¸Đˇ" };
static char PY_mb_xin[] = { "ĐÄĐĂĐžĐÁĐŔĐżĐÂĐ˝ĐĹĐĆ" };
static char PY_mb_xing[] = { "ĐËĐÇĐĘĐÉĐČĐĚĐĎĐÎĐÍĐŃĐÓĐŐĐŇĐÔ" };
static char PY_mb_xiong[] = { "Đ×ĐÖĐŮĐÚĐŘĐŰĐÜ" };
static char PY_mb_xiu[] = { "ËŢĐÝĐŢĐßĐŕĐăĐĺĐäĐâĐá" };
static char PY_mb_xu[] = { "ĐçĐëĐéĐęĐčĐćĐěĐíĐńĐňĐđĐôĐ÷ĐřĐďĐöĐőĐîÓő" };
static char PY_mb_xuan[] = { "ĐůĐűĐúĐţĐüĐýŃĄŃ˘Ń¤ŃŁ" };
static char PY_mb_xue[] = { "Ď÷ŃĽŃŚŃ¨Ń§ŃŠŃŞ" };
static char PY_mb_xun[] = { "ŃŤŃŹŃ°Ń˛ŃŽŃąŃŻŃ­ŃľŃśŃ´Ń¸ŃˇŃł" };
static char PY_mb_ya[] = { "ŃžŃšŃ˝ŃşŃťŃźŃŔŃżŃÁŃÂŃÄŃĂŃĆŃĹŃÇŃČ" };
static char PY_mb_yan[] = { "ŃĘŃĚŃÍŃÉŃËŃÓŃĎŃÔŃŇŃŘŃ×ŃĐŃÎŃÖŃŃŃŐŃŮŃÜŃÚŃŰŃÝŃáŃĺŃâŃäŃçŃŢŃéŃčŃßŃćŃăŃŕ" };
static char PY_mb_yang[] = { "ŃëŃęŃíŃěŃďŃňŃôŃîŃđŃńŃóŃöŃřŃőŃ÷ŃůŃú" };
static char PY_mb_yao[] = { "˝ÄŃýŃüŃűŇ˘ŇŚŇ¤ŇĽŇĄŇŁŃţŇ§Ň¨ŇŠŇŞŇŤÔż" };
static char PY_mb_ye[] = { "ŇŹŇ­ŇŻŇŽŇ˛ŇąŇ°ŇľŇśŇˇŇłŇšŇ´ŇşŇ¸" };
static char PY_mb_yi[] = { "ŇťŇÁŇÂŇ˝ŇŔŇżŇźŇžŇÇŇÄŇĘŇËŇĚŇČŇĆŇĹŇĂŇÉŇÍŇŇŇŃŇÔŇÓŇĎŇĐŇÎŇĺŇÚŇäŇŐŇéŇŕŇŮŇěŇŰŇÖŇëŇŘŇ×ŇďŇčŇßŇćŇęŇîŇÝŇâŇçŇŢŇáŇăŇíŇÜ" };
static char PY_mb_yin[] = { "ŇňŇőŇöŇđŇńŇôŇóŇ÷ŇúŇůŇřŇüŇýŇűŇţÓĄ" };
static char PY_mb_ying[] = { "ÓŚÓ˘Ó¤Ó§ÓŁÓĽÓ­ÓŻÓŤÓ¨ÓŠÓŞÓŹÓŽÓąÓ°ÓłÓ˛" };
static char PY_mb_yo[] = { "Ó´" };
static char PY_mb_yong[] = { "ÓśÓľÓ¸ÓšÓşÓˇÓŔÓ˝ÓžÓÂÓżÓÁÓźÓťÓĂ" };
static char PY_mb_you[] = { "ÓĹÓÇÓÄÓĆÓČÓÉÓĚÓĘÓÍÓËÓÎÓŃÓĐÓĎÓÖÓŇÓ×ÓÓÓŐÓÔ" };
static char PY_mb_yu[] = { "ÓŘÓŮÓĺÓÚÓčÓŕÓŰÓăÓáÓéÓćÓçÓäÓâÓŢÓÜÓÝÓßÓëÓîÓěÓđÓęÓíÓďÓńÔŚÓóÓýÓôÓüÓřÔĄÔ¤ÓňÓűÓ÷Ô˘ÓůÔŁÓöÓúÓţÔĽ" };
static char PY_mb_yuan[] = { "ÔŠÔ§Ô¨ÔŞÔąÔ°ÔŤÔ­Ô˛ÔŹÔŽÔľÔ´ÔłÔŻÔśÔˇÔšÔşÔ¸" };
static char PY_mb_yue[] = { "ÔťÔźÔÂÔŔÔĂÔÄÔžÔÁÔ˝" };
static char PY_mb_yun[] = { "ÔĆÔČÔÇÔĹÔĘÔÉÔĐÔËÔÎÔÍÔĎÔĚ" };
static char PY_mb_za[] = { "ÔŃÔÓÔŇŐŚ" };
static char PY_mb_zai[] = { "ÔÖÔŐÔÔÔ×ÔŘÔŮÔÚ×Đ" };
static char PY_mb_zan[] = { "ÔŰÔÜÔÝÔŢ" };
static char PY_mb_zang[] = { "ÔßÔŕÔá" };
static char PY_mb_zao[] = { "ÔâÔăÔäÔçÔćÔéÔčÔĺÔîÔíÔěÔëÔďÔę" };
static char PY_mb_ze[] = { "ÔňÔńÔóÔđ" };
static char PY_mb_zei[] = { "Ôô" };
static char PY_mb_zen[] = { "Ôő" };
static char PY_mb_zeng[] = { "ÔöÔ÷Ôů" };
static char PY_mb_zha[] = { "ÔűÔüÔúÔýÔţŐ˘ŐĄŐŁŐ§ŐŠŐ¨ŐĽ×ő" };
static char PY_mb_zhai[] = { "ŐŤŐŞŐŹľÔŐ­ŐŽŐŻ" };
static char PY_mb_zhan[] = { "Ő´ŐąŐłŐ˛Ő°ŐśŐšŐľŐ¸ŐˇŐźŐ˝ŐťŐžŐŔŐżŐş" };
static char PY_mb_zhang[] = { "ł¤ŐĹŐÂŐĂŐÄŐÁŐÇŐĆŐÉŐĚŐĘŐČŐÍŐËŐĎŐÎóŻ" };
static char PY_mb_zhao[] = { "ŐĐŐŃŐŇŐÓŐŮŐ×ŐÔŐŐŐÖŐŘ×Ś" };
static char PY_mb_zhe[] = { "ŐÚŐŰŐÜŐÝŐŢŐßŐŕŐâŐăŐá×Ĺ" };
static char PY_mb_zhen[] = { "ŐęŐëŐěŐäŐćŐčŐĺŐçŐéŐďŐíŐîŐóŐńŐňŐđÖĄ" };
static char PY_mb_zheng[] = { "ŐůŐ÷ŐúŐőŐřŐöŐôŐüŐűŐýÖ¤ÖŁŐţÖ˘" };
static char PY_mb_zhi[] = { "ÖŽÖ§Ö­ÖĽÖ¨ÖŚÖŞÖŻÖŤÖŹÖŠÖ´ÖśÖąÖľÖ°Ö˛ÖłÖšÖťÖźÖˇÖ˝Ö¸ÖşÖÁÖžÖĆÖÄÖÎÖËÖĘÖĹÖżÖČÖÂÖŔÖĚÖĎÖÇÖÍÖÉÖĂ" };
static char PY_mb_zhong[] = { "ÖĐÖŇÖŐÖŃÖÓÖÔÖ×ÖÖÖŮÖÚÖŘ" };
static char PY_mb_zhou[] = { "ÖÝÖŰÖßÖÜÖŢÖŕÖáÖâÖăÖäÖćÖçÖĺÖč" };
static char PY_mb_zhu[] = { "ÖěÖďÖęÖéÖîÖíÖëÖńÖňÖđÖ÷ÖôÖóÖöÖő×ĄÖú×˘Öü×¤Öů×ŁÖřÖűÖţÖý" };
static char PY_mb_zhua[] = { "×Ľ" };
static char PY_mb_zhuai[] = { "×§" };
static char PY_mb_zhuan[] = { "×¨×Š×Ş×Ť×­" };
static char PY_mb_zhuang[] = { "×ą×Ż×Ž×°×ł×´´ą×˛" };
static char PY_mb_zhui[] = { "×ˇ×ľ×ś×š×ş×¸" };
static char PY_mb_zhun[] = { "×ť×ź" };
static char PY_mb_zhuo[] = { "×ż×ž×˝×Ŕ×Ć×Â×Ç×Ă×Ä×Á" };
static char PY_mb_zi[] = { "×Î×Č×É×Ë×Ę×Í×Ě×Ń×Ó×Ď×Ň×Ö×Ô×Ő" };
static char PY_mb_zong[] = { "×Ú×Ű×Ř×Ů×××Ü×Ý" };
static char PY_mb_zou[] = { "×Ţ×ß×ŕ×á" };
static char PY_mb_zu[] = { "×â×ă×ä×ĺ×ç×č×é×ć" };
static char PY_mb_zuan[] = { "×Ź×ë×ę" };
static char PY_mb_zui[] = { "×ě×î×ď×í" };
static char PY_mb_zun[] = { "×đ×ń" };
static char PY_mb_zuo[] = { "×ň×ó×ô×÷×ř×ů×ö" };
static char PY_mb_space[] = { "" };

/*"Ć´ŇôĘäČëˇ¨˛éŃŻÂëąí,śţźś×ÖÄ¸Ë÷Ňýąí(index)"*/
static struct PY_index  PY_index_a[]={{"",PY_mb_a},
{"i",PY_mb_ai},
{"n",PY_mb_an},
{"ng",PY_mb_ang},
{"o",PY_mb_ao}};
static struct PY_index  PY_index_b[]={{"a",PY_mb_ba},
{"ai",PY_mb_bai},
{"an",PY_mb_ban},
{"ang",PY_mb_bang},
{"ao",PY_mb_bao},
{"ei",PY_mb_bei},
{"en",PY_mb_ben},
{"eng",PY_mb_beng},
{"i",PY_mb_bi},
{"ian",PY_mb_bian},
{"iao",PY_mb_biao},
{"ie",PY_mb_bie},
{"in",PY_mb_bin},
{"ing",PY_mb_bing},
{"o",PY_mb_bo},
{"u",PY_mb_bu}};
static struct PY_index  PY_index_c[]={{"a",PY_mb_ca},
{"ai",PY_mb_cai},
{"an",PY_mb_can},
{"ang",PY_mb_cang},
{"ao",PY_mb_cao},
{"e",PY_mb_ce},
{"eng",PY_mb_ceng},
{"ha",PY_mb_cha},
{"hai",PY_mb_chai},
{"han",PY_mb_chan},
{"hang",PY_mb_chang},
{"hao",PY_mb_chao},
{"he",PY_mb_che},
{"hen",PY_mb_chen},
{"heng",PY_mb_cheng},
{"hi",PY_mb_chi},
{"hong",PY_mb_chong},
{"hou",PY_mb_chou},
{"hu",PY_mb_chu},
{"huai",PY_mb_chuai},
{"huan",PY_mb_chuan},
{"huang",PY_mb_chuang},
{"hui",PY_mb_chui},
{"hun",PY_mb_chun},
{"huo",PY_mb_chuo},
{"i",PY_mb_ci},
{"ong",PY_mb_cong},
{"ou",PY_mb_cou},
{"u",PY_mb_cu},
{"uan",PY_mb_cuan},
{"ui",PY_mb_cui},
{"un",PY_mb_cun},
{"uo",PY_mb_cuo}};
static struct PY_index  PY_index_d[]={{"a",PY_mb_da},
{"ai",PY_mb_dai},
{"an",PY_mb_dan},
{"ang",PY_mb_dang},
{"ao",PY_mb_dao},
{"e",PY_mb_de},
{"eng",PY_mb_deng},
{"i",PY_mb_di},
{"ian",PY_mb_dian},
{"iao",PY_mb_diao},
{"ie",PY_mb_die},
{"ing",PY_mb_ding},
{"iu",PY_mb_diu},
{"ong",PY_mb_dong},
{"ou",PY_mb_dou},
{"u",PY_mb_du},
{"uan",PY_mb_duan},
{"ui",PY_mb_dui},
{"un",PY_mb_dun},
{"uo",PY_mb_duo}};
static struct PY_index  PY_index_e[]={{"",PY_mb_e},
{"n",PY_mb_en},
{"r",PY_mb_er}};
static struct PY_index  PY_index_f[]={{"a",PY_mb_fa},
{"an",PY_mb_fan},
{"ang",PY_mb_fang},
{"ei",PY_mb_fei},
{"en",PY_mb_fen},
{"eng",PY_mb_feng},
{"o",PY_mb_fo},
{"ou",PY_mb_fou},
{"u",PY_mb_fu}};
static struct PY_index  PY_index_g[]={{"a",PY_mb_ga},
{"ai",PY_mb_gai},
{"an",PY_mb_gan},
{"ang",PY_mb_gang},
{"ao",PY_mb_gao},
{"e",PY_mb_ge},
{"ei",PY_mb_gei},
{"en",PY_mb_gen},
{"eng",PY_mb_geng},
{"ong",PY_mb_gong},
{"ou",PY_mb_gou},
{"u",PY_mb_gu},
{"ua",PY_mb_gua},
{"uai",PY_mb_guai},
{"uan",PY_mb_guan},
{"uang",PY_mb_guang},
{"ui",PY_mb_gui},
{"un",PY_mb_gun},
{"uo",PY_mb_guo}};
static struct PY_index  PY_index_h[]={{"a",PY_mb_ha},
{"ai",PY_mb_hai},
{"an",PY_mb_han},
{"ang",PY_mb_hang},
{"ao",PY_mb_hao},
{"e",PY_mb_he},
{"ei",PY_mb_hei},
{"en",PY_mb_hen},
{"eng",PY_mb_heng},
{"ong",PY_mb_hong},
{"ou",PY_mb_hou},
{"u",PY_mb_hu},
{"ua",PY_mb_hua},
{"uai",PY_mb_huai},
{"uan",PY_mb_huan},
{"uang ",PY_mb_huang},
{"ui",PY_mb_hui},
{"un",PY_mb_hun},
{"uo",PY_mb_huo}};
static struct PY_index  PY_index_i[]={{"",PY_mb_space}};
static struct PY_index  PY_index_j[]={{"i",PY_mb_ji},
{"ia",PY_mb_jia},
{"ian",PY_mb_jian},
{"iang",PY_mb_jiang},
{"iao",PY_mb_jiao},
{"ie",PY_mb_jie},
{"in",PY_mb_jin},
{"ing",PY_mb_jing},
{"iong",PY_mb_jiong},
{"iu",PY_mb_jiu},
{"u",PY_mb_ju},
{"uan",PY_mb_juan},
{"ue",PY_mb_jue},
{"un",PY_mb_jun}};
static struct PY_index  PY_index_k[]={{"a",PY_mb_ka},
{"ai",PY_mb_kai},
{"an",PY_mb_kan},
{"ang",PY_mb_kang},
{"ao",PY_mb_kao},
{"e",PY_mb_ke},
{"en",PY_mb_ken},
{"eng",PY_mb_keng},
{"ong",PY_mb_kong},
{"ou",PY_mb_kou},
{"u",PY_mb_ku},
{"ua",PY_mb_kua},
{"uai",PY_mb_kuai},
{"uan",PY_mb_kuan},
{"uang",PY_mb_kuang},
{"ui",PY_mb_kui},
{"un",PY_mb_kun},
{"uo",PY_mb_kuo}};
static struct PY_index  PY_index_l[]={{"a",PY_mb_la},
{"ai",PY_mb_lai},
{"an",PY_mb_lan},
{"ang",PY_mb_lang},
{"ao",PY_mb_lao},
{"e",PY_mb_le},
{"ei",PY_mb_lei},
{"eng",PY_mb_leng},
{"i",PY_mb_li},
{"ian",PY_mb_lian},
{"iang",PY_mb_liang},
{"iao",PY_mb_liao},
{"ie",PY_mb_lie},
{"in",PY_mb_lin},
{"ing",PY_mb_ling},
{"iu",PY_mb_liu},
{"ong",PY_mb_long},
{"ou",PY_mb_lou},
{"u",PY_mb_lu},
{"uan",PY_mb_luan},
{"ue",PY_mb_lue},
{"un",PY_mb_lun},
{"uo",PY_mb_luo},
{"v",PY_mb_lv}};
static struct PY_index  PY_index_m[]={{"a",PY_mb_ma},
{"ai",PY_mb_mai},
{"an",PY_mb_man},
{"ang",PY_mb_mang},
{"ao",PY_mb_mao},
{"e",PY_mb_me},
{"ei",PY_mb_mei},
{"en",PY_mb_men},
{"eng",PY_mb_meng},
{"i",PY_mb_mi},
{"ian",PY_mb_mian},
{"iao",PY_mb_miao},
{"ie",PY_mb_mie},
{"in",PY_mb_min},
{"ing",PY_mb_ming},
{"iu",PY_mb_miu},
{"o",PY_mb_mo},
{"ou",PY_mb_mou},
{"u",PY_mb_mu}};
static struct PY_index  PY_index_n[]={{"a",PY_mb_na},
{"ai",PY_mb_nai},
{"an",PY_mb_nan},
{"ang",PY_mb_nang},
{"ao",PY_mb_nao},
{"e",PY_mb_ne},
{"ei",PY_mb_nei},
{"en",PY_mb_nen},
{"eng",PY_mb_neng},
{"i",PY_mb_ni},
{"ian",PY_mb_nian},
{"iang",PY_mb_niang},
{"iao",PY_mb_niao},
{"ie",PY_mb_nie},
{"in",PY_mb_nin},
{"ing",PY_mb_ning},
{"iu",PY_mb_niu},
{"ong",PY_mb_nong},
{"u",PY_mb_nu},
{"uan",PY_mb_nuan},
{"ue",PY_mb_nue},
{"uo",PY_mb_nuo},
{"v",PY_mb_nv}};
static struct PY_index  PY_index_o[]={{"",PY_mb_o},
{"u",PY_mb_ou}};
static struct PY_index  PY_index_p[]={{"a",PY_mb_pa},
{"ai",PY_mb_pai},
{"an",PY_mb_pan},
{"ang",PY_mb_pang},
{"ao",PY_mb_pao},
{"ei",PY_mb_pei},
{"en",PY_mb_pen},
{"eng",PY_mb_peng},
{"i",PY_mb_pi},
{"ian",PY_mb_pian},
{"iao",PY_mb_piao},
{"ie",PY_mb_pie},
{"in",PY_mb_pin},
{"ing",PY_mb_ping},
{"o",PY_mb_po},
{"ou",PY_mb_pou},
{"u",PY_mb_pu}};
static struct PY_index  PY_index_q[]={{"i",PY_mb_qi},
{"ia",PY_mb_qia},
{"ian",PY_mb_qian},
{"iang",PY_mb_qiang},
{"iao",PY_mb_qiao},
{"ie",PY_mb_qie},
{"in",PY_mb_qin},
{"ing",PY_mb_qing},
{"iong",PY_mb_qiong},
{"iu",PY_mb_qiu},
{"u",PY_mb_qu},
{"uan",PY_mb_quan},
{"ue",PY_mb_que},
{"un",PY_mb_qun}};
static struct PY_index  PY_index_r[]={{"an",PY_mb_ran},
{"ang",PY_mb_rang},
{"ao",PY_mb_rao},
{"e",PY_mb_re},
{"en",PY_mb_ren},
{"eng",PY_mb_reng},
{"i",PY_mb_ri},
{"ong",PY_mb_rong},
{"ou",PY_mb_rou},
{"u",PY_mb_ru},
{"uan",PY_mb_ruan},
{"ui",PY_mb_rui},
{"un",PY_mb_run},
{"uo",PY_mb_ruo}};
static struct PY_index  PY_index_s[]={{"a",PY_mb_sa},
{"ai",PY_mb_sai},
{"an",PY_mb_san},
{"ang",PY_mb_sang},
{"ao",PY_mb_sao},
{"e",PY_mb_se},
{"en",PY_mb_sen},
{"eng",PY_mb_seng},
{"ha",PY_mb_sha},
{"hai",PY_mb_shai},
{"han",PY_mb_shan},
{"hang ",PY_mb_shang},
{"hao",PY_mb_shao},
{"he",PY_mb_she},
{"hen",PY_mb_shen},
{"heng",PY_mb_sheng},
{"hi",PY_mb_shi},
{"hou",PY_mb_shou},
{"hu",PY_mb_shu},
{"hua",PY_mb_shua},
{"huai",PY_mb_shuai},
{"huan",PY_mb_shuan},
{"huang",PY_mb_shuang},
{"hui",PY_mb_shui},
{"hun",PY_mb_shun},
{"huo",PY_mb_shuo},
{"i",PY_mb_si},
{"ong",PY_mb_song},
{"ou",PY_mb_sou},
{"u",PY_mb_su},
{"uan",PY_mb_suan},
{"ui",PY_mb_sui},
{"un",PY_mb_sun},
{"uo",PY_mb_suo}};
static struct PY_index  PY_index_t[]={{"a",PY_mb_ta},
{"ai",PY_mb_tai},
{"an",PY_mb_tan},
{"ang",PY_mb_tang},
{"ao",PY_mb_tao},
{"e",PY_mb_te},
{"eng",PY_mb_teng},
{"i",PY_mb_ti},
{"ian",PY_mb_tian},
{"iao",PY_mb_tiao},
{"ie",PY_mb_tie},
{"ing",PY_mb_ting},
{"ong",PY_mb_tong},
{"ou",PY_mb_tou},
{"u",PY_mb_tu},
{"uan",PY_mb_tuan},
{"ui",PY_mb_tui},
{"un",PY_mb_tun},
{"uo",PY_mb_tuo}};
static struct PY_index  PY_index_u[]={{"",PY_mb_space}};
static struct PY_index  PY_index_v[]={{"",PY_mb_space}};
static struct PY_index  PY_index_w[]={{"a",PY_mb_wa},
{"ai",PY_mb_wai},
{"an",PY_mb_wan},
{"ang",PY_mb_wang},
{"ei",PY_mb_wei},
{"en",PY_mb_wen},
{"eng",PY_mb_weng},
{"o",PY_mb_wo},
{"u",PY_mb_wu}};
static struct PY_index PY_index_x[]={{"i",PY_mb_xi},
{"ia",PY_mb_xia},
{"ian",PY_mb_xian},
{"iang",PY_mb_xiang},
{"iao",PY_mb_xiao},
{"ie",PY_mb_xie},
{"in",PY_mb_xin},
{"ing",PY_mb_xing},
{"iong",PY_mb_xiong},
{"iu",PY_mb_xiu},
{"u",PY_mb_xu},
{"uan",PY_mb_xuan},
{"ue",PY_mb_xue},
{"un",PY_mb_xun}};
static struct PY_index PY_index_y[]={{"a",PY_mb_ya},
{"an",PY_mb_yan},
{"ang",PY_mb_yang},
{"ao",PY_mb_yao},
{"e",PY_mb_ye},
{"i",PY_mb_yi},
{"in",PY_mb_yin},
{"ing",PY_mb_ying},
{"o",PY_mb_yo},
{"ong",PY_mb_yong},
{"ou",PY_mb_you},
{"u",PY_mb_yu},
{"uan",PY_mb_yuan},
{"ue",PY_mb_yue},
{"un",PY_mb_yun}};
static struct PY_index PY_index_z[]={{"a",PY_mb_za},
{"ai",PY_mb_zai},
{"an",PY_mb_zan},
{"ang",PY_mb_zang},
{"ao",PY_mb_zao},
{"e",PY_mb_ze},
{"ei",PY_mb_zei},
{"en",PY_mb_zen},
{"eng",PY_mb_zeng},
{"ha",PY_mb_zha},
{"hai",PY_mb_zhai},
{"han",PY_mb_zhan},
{"hang",PY_mb_zhang},
{"hao",PY_mb_zhao},
{"he",PY_mb_zhe},
{"hen",PY_mb_zhen},
{"heng",PY_mb_zheng},
{"hi",PY_mb_zhi},
{"hong",PY_mb_zhong},
{"hou",PY_mb_zhou},
{"hu",PY_mb_zhu},
{"hua",PY_mb_zhua},
{"huai",PY_mb_zhuai},
{"huan",PY_mb_zhuan},
{"huang",PY_mb_zhuang},
{"hui",PY_mb_zhui},
{"hun",PY_mb_zhun},
{"huo",PY_mb_zhuo},
{"i",PY_mb_zi},
{"ong",PY_mb_zong},
{"ou",PY_mb_zou},
{"u",PY_mb_zu},
{"uan",PY_mb_zuan},
{"ui",PY_mb_zui},
{"un",PY_mb_zun},
{"uo",PY_mb_zuo}};

static struct PY_index  PY_index_end[]={{"",PY_mb_space}};

static const int PY_index_headsize[]={
	5,
	16,
	33,
	20,
	3,
	9,
	19,
	19,
	0,
	14,
	18,
	24,
	19,
	23,
	2,
	17,
	14,
	14,
	34,
	19,
	0,
	0,
	9,
	14,
	15,
	36
};
/*��������ĸ������*/
static struct PY_index  *PY_index_headletter[]={	PY_index_a,
PY_index_b,
PY_index_c,
PY_index_d,
PY_index_e,
PY_index_f,
PY_index_g,
PY_index_h,
PY_index_i,
PY_index_j,
PY_index_k,
PY_index_l,
PY_index_m,
PY_index_n,
PY_index_o,
PY_index_p,
PY_index_q,
PY_index_r,
PY_index_s,
PY_index_t,
PY_index_u,
PY_index_v,
PY_index_w,
PY_index_x,
PY_index_y,
PY_index_z,
PY_index_end}; 

enum InputStatus
{
	eInputEng = 0,
	eInputChi,
	eSelPY,
	eSelHZ,
	eInputNum
};
class JGBKFont;
class JInputSystem
{
private:
	JGBKFont* mBitmapFont12;
	bool mIsInputActive;

	float mTimer;
	//store input STRING
	char  mInPut[512];
	char * mpInput;
	//store input PY
	char  mPY[16];
	//pointer to the HZ select string.
	char *mHZ;
	//input system status.
	InputStatus mStatus;
	//PY select
	bool mEnablePYSel;
	int mPYShowFirstIndex;
	int mPYSelIndex;
	int mPYSelTableSize;

	//HZ select
	int mHZShowFirstIndex;
	int mHZSelIndex;
	int mHZSelTableSize;
	bool mIsHZ_H;

	bool GetInputKey(int& a, int& b, int& c);
	char* GetChinese(char* str);
	int GetNexPYIndex(char* str, PY_index* &py_index);
	void printf12(char* str,float x, float y, float scale=1.0f, PIXEL_TYPE color=ARGB(255,255,255,255),int type=JGETEXT_LEFT);
	int  strlen12( char* buff, float scale=1.0f);


public:
	static JInputSystem* m_pJInputSystem;
	static JInputSystem * GetInstance();
	static void Destory();
	JInputSystem(void);
	virtual ~JInputSystem(void);

	//Active flag
	void EnableInputMode(char *buf){buf[0]=0;mpInput = buf; mIsInputActive=true;}
	void DisableInputMode(){mpInput = NULL; mIsInputActive=false;}
	//void SetInputActive(bool f){mIsInputActive=f;}
	bool GetIsInputActive(){return mIsInputActive;}

	JGBKFont* GetFont12(){return mBitmapFont12;}

	//Update
	void Update();
	void UpdateInputEng();
	void UpdateInputChi();
	void UpdateSelPY();
	void UpdateSelHZ();
	void UpdateSelHZ_H();
	void UpdateInputNum();

	void Draw();
	void DrawInputString(float x,float y);
	void DrawStr1(char* str, float x, float y, u32 color=ARGB(255,0,0,0));
	void DrawStatus(float x,float y);
	void DrawPYInput(float x,float y);
	void DrawPYSel(float x,float y);
	void DrawHZSel(float x,float y);
	void DrawHZSel_H(float x,float y);
	void DrawInputHelp(float x, float y);

	char * GetInputString(){return mInPut;}
};
#endif

