from migen import *
from litex.gen import *

from litex.soc.interconnect.csr import *
from litex.soc.interconnect.csr_eventmanager import *

class Conv(LiteXModule):
    def __init__(self):
        # Define 9 CSRs for the 9 inputs
        self.window0    = CSRStorage(32, name='window0')
        self.window1    = CSRStorage(32, name='window1')
        self.window2    = CSRStorage(32, name='window2')
        self.window3    = CSRStorage(32, name='window3')
        self.window4    = CSRStorage(32, name='window4')
        self.window5    = CSRStorage(32, name='window5')
        self.window6    = CSRStorage(32, name='window6')
        self.window7    = CSRStorage(32, name='window7')
        self.window8    = CSRStorage(32, name='window8')

        # One CSRStatus for output
        self.result = CSRStatus(32, name="result")

        self.specials += Instance("convolution",
            i_in0     = self.window0.storage,
            i_in1     = self.window1.storage,
            i_in2     = self.window2.storage,
            i_in3     = self.window3.storage,
            i_in4     = self.window4.storage,
            i_in5     = self.window5.storage,
            i_in6     = self.window6.storage,
            i_in7     = self.window7.storage,
            i_in8     = self.window7.storage,
            o_out     = self.result.status
        )
        
