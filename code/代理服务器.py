import sys

def solve():
    input = sys.stdin.read().split()
    ptr = 0
    while ptr < len(input):
        # 读取代理服务器
        n = int(input[ptr].strip())
        ptr += 1
        proxies = set()
        for _ in range(n):
            proxies.add(input[ptr].strip())
            ptr += 1
        
        # 读取目标服务器
        m = int(input[ptr].strip())
        ptr += 1
        servers = []
        for _ in range(m):
            servers.append(input[ptr].strip())
            ptr += 1
        
        # 贪心算法
        current_proxies = proxies.copy()
        switches = 0
        possible = True
        
        for server in servers:
            if server in current_proxies:
                current_proxies.remove(server)
                if not current_proxies:  # 无可用代理时切换
                    switches += 1
                    current_proxies = proxies - {server}  # 排除当前冲突的代理
                    if not current_proxies:  # 切换后仍无可用代理
                        possible = False
                        break
        
        print(switches if possible else -1)

solve()