og = 13
vg = 8
navi = 7
eg = 6
fnc = 5
inf = 5
rng = 5
vp = 5
nip = 2

res = {
    'og': '',
    'vg': '',
    'navi': '',
    'eg': '',
    'fnc': '',
    'inf': '',
    'rng': '',
    'vp': '',
    'nip': ''
}

res1 = {
    'og': '',
    'vg': '',
    'navi': '',
    'eg': '',
    'fnc': '',
    'inf': '',
    'rng': '',
    'vp': '',
    'nip': ''
}

res2 = {
    'og': '',
    'vg': '',
    'navi': '',
    'eg': '',
    'fnc': '',
    'inf': '',
    'rng': '',
    'vp': '',
    'nip': ''
}

for team in res:
    res1[team] = [0, 0, 0, 0, 0, 0, 0]
    res2[team] = [0, 0, 0, 0, 0, 0, 0]
    res[team] = [0, 0, 0, 0, 0, 0, 0]

pegnip = [0.472656, 0.429688, 0.097656]
pegvp = [0.25, 0.5, 0.25]
pfncrng = [0.23551, 0.499567, 0.264922]
pfncvp = [0.140625, 0.46875, 0.390625]
pinfnip = [0.214753, 0.497323, 0.287924]
pinfrng = [0.195787, 0.493382, 0.310831]
pnavivg = [0.097656, 0.429688, 0.472656]
pogvg = [0.25, 0.5, 0.25]

for egnip in range(3):
    for egvp in range(3):
        for fncrng in range(3):
            for fncvp in range(3):
                for infnip in range(3):
                    for infrng in range(3):
                        for navivg in range(3):
                            for ogvg in range(3):
                                cp = pegnip[egnip]*pegvp[egvp]*pfncrng[fncrng]*pfncvp[fncvp] * \
                                    pinfnip[infnip]*pinfrng[infrng] * \
                                    pnavivg[navivg]*pogvg[ogvg]
                                scores = {
                                    'og': og + ogvg,
                                    'vg': vg + 2-ogvg + 2-navivg,
                                    'navi': navi + navivg,
                                    'eg': eg + egnip + egvp,
                                    'fnc': fnc + fncrng + fncvp,
                                    'inf': inf + infnip + infrng,
                                    'rng': rng + 2-fncrng + 2-infrng,
                                    'vp': vp + 2-egvp + 2-fncvp,
                                    'nip': nip + 2-egnip + 2-infnip
                                }
                                rank = {}
                                s4 = 0
                                g4 = 10
                                s8 = 0
                                g8 = 10
                                for team in scores:
                                    higher = 0
                                    for team2 in scores:
                                        if scores[team2] > scores[team]:
                                            higher += 1
                                    rank[team] = higher
                                    if higher < 4:
                                        s4 = max(s4, higher)
                                    if higher < 8:
                                        s8 = max(s8, higher)
                                    if higher >= 4:
                                        g4 = min(g4, higher)
                                    if higher >= 8:
                                        g8 = 8
                                if g4 > 4:
                                    for team in scores:
                                        if rank[team] == s4:
                                            res1[team][g4-3] += cp
                                            res[team][g4-3] += cp
                                if g8 > 8:
                                    for team in scores:
                                        if rank[team] == s8:
                                            res2[team][9-s8] += cp
                                            res[team][9-s8] += cp
print(res1)
print(res2)
print(res)
