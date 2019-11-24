 `timescale 1ns / 1ps

module checksim_101();
    reg clk,rst;
    reg x;
    wire y;
    check_101 ch(.clk(clk),.rst(rst),.x(x),.y(y));
    initial begin
        clk = 0;
        rst = 1;
        #5 rst = 0;
        #3 rst = 1;
        #40 x = 1;
        #40 x = 1;
        #40 x = 0;
        #40 x = 1;
        #40 x = 1;
        #40 x = 0;
        #40 x = 0;
        #40 x = 1;
        #40 x = 0;
        #40 x = 1;
        #40 x = 0;
        #40 x = 0;
        #40 x = 1;
        #40 x = 0;
        #40 x = 0;
        #40 x = 1;
        #40 x = 0;
        #40 x = 1;
        #40 x = 0;
    end
    always #50 clk = ~clk;
endmodule