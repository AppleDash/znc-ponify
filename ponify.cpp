#include <znc/main.h>
#include <znc/Modules.h>
#include <znc/Chan.h>
#include <znc/User.h>
#include <znc/IRCNetwork.h>
#include <map>

#define CSMap std::map<CString, CString>

class CPonifyMod : public CModule {
public:
	CSMap replace;
	MODCONSTRUCTOR(CPonifyMod) {
		SetupMap();
	}
	virtual ~CPonifyMod() { } 

	virtual EModRet OnUserMsg(CString &sTarget, CString &sMessage) {
		PonifyString(sMessage);
		PutIRC("PRIVMSG " + sTarget + " :" + sMessage);
		return HALTCORE;
	}

private:
	void PonifyString(CString &str) {
		CSMap::iterator iter;
		VCString out;
		CString space = " ";
		str.Split(space, out);
		for (iter = replace.begin(); iter != replace.end(); ++iter) {
			CString k = iter->first;
			CString v = iter->second;
			for(VCString::size_type i = 0; i != out.size(); i++) {
				CString word = out[i];
				if (word.AsLower().Equals(k.AsLower())) {
					str.Replace(word, v);
				}
			}
		}
	}
	void SetupMap() {
		replace["confound those dover boys"] = "confound these ponies";
		replace["victoria's secret"] = "rarity's secret";
		replace["wolverhampton"] = "trotterhampton";
		replace["sure as hell"] = "sure as hay";
		replace["philadelphia"] = "fillydelphia";
		replace["girlfriends"] = "fillyfriends";
		replace["no one else"] = "no pony else";
		replace["grooveshark"] = "groovepony";
		replace["doctor who"] = "doctor whooves";
		replace["boyfriends"] = "coltfriends";
		replace["handprints"] = "hoofprints";
		replace["stalingrad"] = "stalliongrad";
		replace["nottingham"] = "trottingham";
		replace["girlfriend"] = "fillyfriend";
		replace["foursquare"] = "4hoof";
		replace["footprints"] = "hoofprints";
		replace["gentlemen"] = "gentlecolts";
		replace["everybody"] = "everypony";
		replace["gentleman"] = "gentlecolt";
		replace["high-five"] = "hoof-five";
		replace["footprint"] = "hoofprint";
		replace["wikipedia"] = "wikiponia";
		replace["trollface"] = "paraspriteface";
		replace["old-timer"] = "old-trotter";
		replace["boyfriend"] = "coltfriend";
		replace["halloween"] = "nightmare night";
		replace["footsteps"] = "hoofsteps";
		replace["manhattan"] = "manehattan";
		replace["handprint"] = "hoofprint";
		replace["trollable"] = "paraspritable";
		replace["children"] = "foals";
		replace["the heck"] = "the hay";
		replace["bro-fist"] = "bro-hoof";
		replace["facepalm"] = "facehoof";
		replace["handmade"] = "hoofmade";
		replace["footstep"] = "hoofstep";
		replace["butthurt"] = "saddle-sore";
		replace["the hell"] = "the hay";
		replace["somebody"] = "somepony";
		replace["american"] = "amareican";
		replace["bro fist"] = "bro hoof";
		replace["naysayer"] = "neighsayer";
		replace["butthurt"] = "flankhurt";
		replace["trolling"] = "paraspriting";
		replace["marathon"] = "mareathon";
		replace["handedly"] = "hoofedly";
		replace["everyone"] = "everypony";
		replace["miracles"] = "mareacles";
		replace["pandora"] = "ponydora";
		replace["america"] = "amareica";
		replace["anybody"] = "anypony";
		replace["cowgirl"] = "cowpony";
		replace["brofist"] = "brohoof";
		replace["groupon"] = "groupony";
		replace["someone"] = "somepony";
		replace["dr. who"] = "dr. whooves";
		replace["persons"] = "ponies";
		replace["miracle"] = "mareacle";
		replace["trolled"] = "parasprited";
		replace["foolish"] = "foalish";
		replace["fapping"] = "clopping";
		replace["dubstep"] = "dubtrot";
		replace["handers"] = "hoofers";
		replace["anyone"] = "anypony";
		replace["tattoo"] = "cutie mark";
		replace["cowboy"] = "cowpony";
		replace["handed"] = "hoofed";
		replace["person"] = "pony";
		replace["dr who"] = "dr whooves";
		replace["ladies"] = "fillies";
		replace["nobody"] = "nopony";
		replace["people"] = "ponies";
		replace["humans"] = "ponies";
		replace["trolls"] = "parasprites";
		replace["women"] = "mares";
		replace["girls"] = "fillies";
		replace["boner"] = "wingboner";
		replace["woman"] = "mare";
		replace["folks"] = "foalks";
		replace["child"] = "foal";
		replace["hands"] = "hooves";
		replace["human"] = "pony";
		replace["yahoo"] = "yahoof";
		replace["money"] = "bits";
		replace["troll"] = "parasprite";
		replace["guys"] = "stallions";
		replace["step"] = "trot";
		replace["feet"] = "hooves";
		replace["walk"] = "saunter";
		replace["foot"] = "hoof";
		replace["fool"] = "foal";
		replace["boys"] = "colts";
		replace["at&t"] = "ap&p";
		replace["girl"] = "filly";
		replace["main"] = "mane";
		replace["hand"] = "hoof";
		replace["ebay"] = "enay";
		replace["fap"] = "clop";
		replace["man"] = "stallion";
		replace["men"] = "stallions";
		replace["hey"] = "hay";
		replace["boy"] = "colt";
		replace["cnn"] = "pnn";
		replace["guy"] = "stallion";
		replace["god"] = "celestia";		
	}
};

NETWORKMODULEDEFS(CPonifyMod, "Ponifies outgoing text.");