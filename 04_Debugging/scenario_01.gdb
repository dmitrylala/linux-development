set pagination off

b 42 if i % 5 == 0
command 1
        echo @@@
        p r.start
        echo @@@
        p r.stop
        echo @@@
        p r.step
        echo @@@
        p i
end

run
quit
