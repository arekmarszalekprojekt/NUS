stare_a = 0;
stare_b = 0;
stare_c = 0;
        for t = 0:0.1:2*pi
            a = round(50*sin(t));
            b = round(50*sin(t-2*pi/3));
            c = round(50*sin(t-4*pi/3));
            krok_a = a - stare_a;
            krok_b = b - stare_b;
            krok_c = c - stare_c;

            fprintf(drukarka, 'a %d b %d c %d\n', [ a b c ]);
            while(drukarka.BytesAvailable == 0)
            end

            while(drukarka.BytesAvailable > 0)
            fscanf(drukarka)
            end
            stare_a = a;
            stare_b = b;
            stare_c = c;
            
        end