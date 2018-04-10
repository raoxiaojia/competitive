from collections import namedtuple

R, C, F, N, B, T = map(int, input().split(' '))
jobs = []
jobs_available = set([i for i in range(N)])


def distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


class Job(object):
    def __init__(self, a, b, x, y, s, f):
        self.start = (a, b)
        self.finish = (x, y)
        self.s = s
        self.f = f

    def __repr__(self):
        return f"start={self.start},finish={self.finish},s={self.s},f={self.f}"

    def distance(self):
        return distance(self.start, self.finish)


for i in range(N):
    data = map(int, input().split(' '))
    jobs.append(Job(*data))


class Car(object):
    def __init__(self):
        self.taken = False
        self.next_free_time = 0
        self.position = (0, 0)
        self.jobs = []


cars = [Car() for i in range(F)]

for t in range(T):
    for j in list(jobs_available):
        if t + jobs[j].distance() >= jobs[j].f:
            jobs_available.remove(j)
    for c in cars:
        if c.next_free_time == t:
            c.taken = False
        if c.taken == False:
            running_max = 0
            best_job = -1
            next_free_time = 0
            for j in jobs_available:
                idle_time = max(jobs[j].s,
                                t + distance(c.position, jobs[j].start)) - t
                if (t + idle_time + jobs[j].distance() <= jobs[j].f):
                    score = ((B + jobs[j].distance()) /
                             (idle_time + jobs[j].distance()))
                    if running_max < score:
                        running_max = score
                        best_job = j
                        next_free_time = t + idle_time + jobs[j].distance()

            if best_job != -1:
                jobs_available.remove(best_job)
                c.taken = True
                c.position = jobs[best_job].finish
                c.next_free_time = next_free_time
                c.jobs.append(best_job)

for c in cars:
    print(' '.join([str(x) for x in [len(c.jobs)] + c.jobs]))
