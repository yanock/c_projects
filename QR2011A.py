from pprint import pprint as pp

def bot_trust(N, Bk, Bv, Ok, Ov, debug = False):
	Bp = 1
	Op = 1
	btn = -1
	sec = 0
	
	while (len(Bk) > 0 or len(Ok) > 0):
		if debug:
			print('')
			pp({'Bk': Bk})
			pp({'Bv': Bv})
			pp({'Ok': Ok})
			pp({'Ov': Ov})
			pp({'Bp': Bp})
			pp({'Op': Op})
			pp({'btn': btn})
			pp({'sec': sec})
			print('')
		
		act = False
		
		if len(Bk) > 0:
			if debug: print('len(Bk) > 0')
			if Bp > Bv[0]:
				if debug: print('Bp > Bv[0] => Bp -= 1')
				Bp -= 1
			elif Bp < Bv[0]:
				if debug: print('Bp < Bv[0] => Bp += 1')
				Bp += 1
			elif btn + 1 == Bk[0]:
				if debug: print('btn + 1 == Bk[0] => btn += 1')
				btn += 1
				Bk.pop(0)
				Bv.pop(0)
				act = True
			else:
				if debug: print('#B waiting')
		
		if len(Ok) > 0:
			if debug: print('len(Ok) > 0')
			if Op > Ov[0]:
				if debug: print('Op > Ov[0] => Op -= 1')
				Op -= 1
			elif Op < Ov[0]:
				if debug: print('Op < Ov[0] => Op += 1')
				Op += 1
			elif btn + 1 == Ok[0] and not act:
				if debug: print('btn + 1 == Ok[0] => btn += 1')
				btn += 1
				Ok.pop(0)
				Ov.pop(0)
				act = True
			else:
				if debug: print('#O waiting')
		
		sec += 1
	
	if debug:
		print('')
		pp({'Bk': Bk})
		pp({'Bv': Bv})
		pp({'Ok': Ok})
		pp({'Ov': Ov})
		pp({'Bp': Bp})
		pp({'Op': Op})
		pp({'btn': btn})
		pp({'sec': sec})
		print('')
	
	return sec

if __name__ == '__main__':
	import sys
	
	debug = True if len(sys.argv) > 1 else False
	
	for input_type in ['sample', 'small', 'large']:
		input_name = sys.argv[0] + '.' + input_type + '.in'
		output_name = input_name.replace('in', 'out')
		
		with open(input_name) as input:
			with open(output_name, 'w') as output:
				T = int(input.readline().strip())
				
				for t in range(T):
					line = input.readline().strip().split(' ')
					N = int(line.pop(0))
					Bk = [(n - 1) / 2 for n in range(1, 2 * N, 2) if line[n - 1] == 'B']
					Bv = [int(line[2 * k + 1]) for k in Bk]
					Ok = [(n - 1) / 2 for n in range(1, 2 * N, 2) if line[n - 1] == 'O']
					Ov = [int(line[2 * k + 1]) for k in Ok]
					
					result = bot_trust(N, Bk, Bv, Ok, Ov, debug)
					output.write('Case #%d: %d\n' % (t + 1, result))
					
					if debug: pp({'t': t, 'bot_trust': result})