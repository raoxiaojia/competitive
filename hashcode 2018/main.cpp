#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <random>
#include <string>
#include <ctime>

using namespace std;

const string inputFile[4] = {
	"b_lovely_landscapes.txt",
	"c_memorable_moments.txt",
	"d_pet_pictures.txt",
	"e_shiny_selfies.txt"
};

const string outputFile[4] = {
	"b.out",
	"c.out",
	"d.out",
	"e.out"
};

typedef vector<string> vstr;

struct Photo {
	int ntag;
	char dir;
	vstr tags;
	int index;
	bool used;
	int i1, i2;
};

vector<Photo> photos,hphotos,vphotos;

typedef pair<int, int> ii;

int main(int argc, char* argv[])
{
	ifstream inf;
	ofstream out;
	srand(time(NULL));
	int tindex;
	cin >> tindex;
	inf.open(inputFile[tindex]);
	int n;
	inf >> n;
	photos.clear();
	for (int i = 0; i < n; i++) {
		Photo tmp;
		inf >> tmp.dir >> tmp.ntag;
		tmp.tags.clear();
		for (int j = 0; j < tmp.ntag; j++) {
			string tmpstr;
			inf >> tmpstr;
			tmp.tags.push_back(tmpstr);
		}
		sort(tmp.tags.begin(), tmp.tags.end());
		photos.push_back(tmp);
	}
	inf.close();
	out.open(outputFile[tindex]);
	hphotos.clear();
	vphotos.clear();
	vector<ii> ans;
	ans.clear();
	vstr last;
	int li = -1;
	last.clear();
	for (int i = 0; i < n; i++) {
		photos[i].index = i;
		photos[i].used = false;
		if (photos[i].dir == 'H') {
			photos[i].i1 = -1;
			photos[i].i2 = -1;
			hphotos.push_back(photos[i]);
		}
		else {
			if (last.size()) {
				vstr vunion;
				set_union(last.begin(), last.end(), photos[i].tags.begin(), photos[i].tags.end(), back_inserter(vunion));
				photos[i].i1 = li;
				photos[i].i2 = i;
				li = -1;
				last.clear();
				hphotos.push_back(photos[i]);
			}
			else {
				last = photos[i].tags;
				li = i;
			}
		}
	}

	cout << "end" <<endl;

	int hp = hphotos.size();
	int vp = vphotos.size();
	cout << hp << ' ' << vp << endl;

	int hpleft = hp;
	int vpleft = vp;
	

	int photoLeft = n;

	vstr prevtags;

	if (hp > 0) {
		ans.emplace_back(hphotos[0].index, -1);
		hphotos[0].used = 1;
		photoLeft--;
		hpleft--;
		prevtags = hphotos[0].tags;
		hphotos[0] = hphotos.back();
		hphotos.pop_back();
	}
	else {
		ans.emplace_back(vphotos[0].index, vphotos[1].index);
		//vphotos.erase(vphotos.begin() + 0);
		//vphotos.erase(vphotos.begin() + 0);
		vphotos[0] = vphotos.back();
		vphotos.pop_back();
		vphotos[1] = vphotos.back();
		vphotos.pop_back();
		photoLeft -= 2;
		vpleft -= 2;
	}

	int score = 0;

	while (photoLeft) {
		int trials = min(200,hpleft);
		if (hpleft % 100 == 0 && hpleft || vpleft % 100 == 0 && vpleft)
			cout << hpleft <<' '<<vpleft<< endl;
		int cur = !hpleft ? 0 : rand() % hpleft;
		int best = -1;
		int bestscore = 0;
		int psize = prevtags.size();
		while (trials) {
			if (!hphotos[cur].used) {
				if (best == -1) {
					best = cur;
				}
				else {
					vstr intersect;
					set_intersection(prevtags.begin(), prevtags.end(), hphotos[cur].tags.begin(), hphotos[cur].tags.end(),back_inserter(intersect));
					int isize = intersect.size();
					int csize = hphotos[cur].tags.size();
					int score = min(isize, min(psize-isize, csize-isize));
					if (score > bestscore) {
						bestscore = score;
						best = cur;
					}
				}
				trials--;
			}
			cur = (cur + 1) % hpleft;
		}

	/*	trials = min(20,vpleft);
		int best1 = -1;
		int bestisize = 500;
		cur = !vpleft?0:rand() % vpleft;
		while (trials) {
			if (!vphotos[cur].used) {
				if (best1 == -1) {
					best1 = cur;
				}
				else {
					vstr intersect;
					set_intersection(prevtags.begin(), prevtags.end(), vphotos[cur].tags.begin(), vphotos[cur].tags.end(), back_inserter(intersect));
					int isize = intersect.size();
					if (abs(isize-0.4*psize) < bestisize) {
						bestisize = isize;
						best1 = cur;
					}
				}
				trials--;
			}
			cur = (cur + 1) % vpleft;
		}

		int best2 = -1;
		int bestnisize = 1000;
		cur = !vpleft?0:rand() % vpleft;
		trials = min(20, vpleft);
		while (trials>=1) {
			if (cur == best1) {
				cur = (cur + 1) % vpleft;
				trials--;
				continue;
			}
			if (!vphotos[cur].used) {
				if (best2 == -1) {
					best2 = cur;
				}
				else {
					vstr intersect;
					set_intersection(prevtags.begin(), prevtags.end(), vphotos[cur].tags.begin(), vphotos[cur].tags.end(), back_inserter(intersect));
					int isize = intersect.size();
					if (isize < bestnisize) {
						bestnisize = isize;
						best2 = cur;
					}
				}
				trials--;
			}
			cur = (cur + 1) % vpleft;
		}

		vstr vunion;
		set_union(vphotos[best1].tags.begin(), vphotos[best1].tags.end(), vphotos[best2].tags.begin(), vphotos[best2].tags.end(), back_inserter(vunion));

		vstr vintersect;

		set_intersection(prevtags.begin(), prevtags.end(), vunion.begin(), vunion.end(), back_inserter(vintersect));

		int vcsize = vunion.size();

		int visize = vintersect.size();
		int vscore = min(visize, min(vcsize - visize, psize - visize));*/
		if (best == -1) break;
		if ( hphotos[best].i1 == -1) {
			score += bestscore;
			ans.emplace_back(hphotos[best].index, -1);
			prevtags = hphotos[best].tags;
			//hphotos.erase(hphotos.begin() + best);
			hphotos[best] = hphotos.back();
			hphotos.pop_back();
			photoLeft--;
			hpleft--;
		}
		else {
			ans.emplace_back(hphotos[best].i1, hphotos[best].i2);
			prevtags = hphotos[best].tags;
			//hphotos.erase(hphotos.begin() + best);
			hphotos[best] = hphotos.back();
			hphotos.pop_back();
			photoLeft--;
			hpleft--;
		}
		/*else {
			ans.emplace_back(vphotos[best1].index, vphotos[best2].index);
			prevtags = vunion;
			//vphotos.erase(vphotos.begin() + max(best1,best2));
			//vphotos.erase(vphotos.begin() + min(best1,best2));
			vphotos[max(best1, best2)] = vphotos.back();
			vphotos.pop_back();
			vphotos[min(best1, best2)] = vphotos.back();
			vphotos.pop_back();
			photoLeft -= 2;
			vpleft -= 2;
		}*/
	}

	out << ans.size() << endl;
	for (auto it = ans.begin(); it < ans.end(); it++) {
		if (it->second == -1) {
			out << it->first << endl;
		}
		else {
			out << it->first << ' ' << it->second << endl;
		}
	}
	out.close();

	cout << "score="<<score << endl;
	return 0;
}