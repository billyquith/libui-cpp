
import re

SRC_H = '../ext/libui/ui.h'
GEN_H = '../src/libui-cpp/uidefs.hpp'


class Writer:
    def __init__(self):
        self._out = []
        self._in = 0
    def indent(self, i=1):
        self._in += i
    def __iadd__(self, t):
        self._out.append('    ' * self._in + t)
        return self
    def __str__(self):
        return '\n'.join(self._out)
        
        
def preprocess(src):
    psrc = []
    for ln in src.split('\n'):
        ci = ln.find('//')
        if ci >= 0:
            ln = ln[:ci]
        psrc.append(ln)
    return '\n'.join(psrc)


def find_enums(src, out):
    out.indent()
    enums = re.findall('_UI_ENUM\((\w+)\)\s*{([^\}]*)}', src)
    for (name, vals) in enums:
        print name, vals
        assert name.startswith('ui')
        ecls = name[2:]
        
        out += 'enum class %s {' % ecls
        out.indent()
        
        if name=='uiModifiers':
            name = 'uiModifier';

        vals = [i.strip() for i in vals.split(',') if i.strip() != '']
        for val in vals:
            print val
            assert val.startswith(name)
            if '=' in val:
                enum, valset = val.split('=')
                enum = enum[len(name):].strip()
                out += '%s = %s,' % (enum, valset.strip())
            else:
                enum = val[len(name):]
                out += '%s,' % enum
            
        out.indent(-1)
        out += '};'
        out += ''
            
    out.indent(-1)
            

def process(src):
    out = Writer()
    out += 'namespace libui {'
    out += ''
    
    src = preprocess(src)
    find_enums(src, out)
    
    out += '} // namespace libui'
    print str(out)
    
    with open(GEN_H, 'w') as f:
        f.write(str(out))

def main():
    with open(SRC_H) as f:        
        process(f.read())

main()
