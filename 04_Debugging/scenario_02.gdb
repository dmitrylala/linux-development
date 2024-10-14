set pagination off

set $count = 0

b range.c:42 if $count <= 35
    command 1
    silent

    if $count >= 28
        echo @@@
        p r.start
        echo @@@
        p r.stop
        echo @@@
        p r.step
        echo @@@
        p i
    end

    set $count = $count + 1
    continue
end

run
quit
