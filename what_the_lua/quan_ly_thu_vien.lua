local books = {}
local users = {}
local transactions = {}

local function main_menu_display()
    print("\nQUAN LY THU VIEN\n")
    print("1 - Quan ly sach")
    print("2 - Quan ly nguoi dung")
    print("3 - Quan ly muon tra sach")
    print("4 - Thoat")
    io.write("\nLua chon: ")
end

local function manage_books()
    while true do
        print("\nQUAN LY SACH\n")
        print("1 - Them sach")
        print("2 - Xoa sach")
        print("3 - Tat ca sach trong thu vien")
        print("4 - Quay lai")
        io.write("\nLua chon: ")
        local choice = io.read()
        if choice == "1" then
            io.write("\nNhap ten sach: ")
            local name = io.read()
            table.insert(books, {name = name, is_borrowed = false})
            print("Them sach thanh cong")
        elseif choice == "2" then
            io.write("\nNhap ten sach can xoa")
            local name = io.read()
            local found = false
            for i, book in ipairs(books) do
                if book.name == name then
                    table.remove(books, i)
                    print("Xoa thanh cong")
                    found = true
                    break
                end
            end
            if not found then
                print("Khong tim thay ten sach: ", name)
            end
        elseif choice == "3" then
            print("Tat ca sach trong thu vien:")
            for i, book in ipairs(books) do
                local book_status
                if not book.is_borrowed then
                    book_status = "Co san"
                else
                    book_status = "Da duoc muon"
                end
                print(i .. "- " .. book.name .. " Trang thai: "  .. book_status)
            end
        elseif choice == "4" then
            break
        else
            print("Lua chon khong hop le")
        end
    end
end

local function manage_users()
    while true do
        print("\nQUAN LY NGUOI DUNG")
        print("1 - Them nguoi dung")
        print("2 - Xoa nguoi dung")
        print("3 - Xem tat ca nguoi dung")
        print("4 - Quay lai")
        io.write("\nLua chon: ")
        local choice = io.read()
        if choice == "1" then
            io.write("Nhap  ten nguoi can them: ")
            local name = io.read()
            table.insert(users, name)
            print("Them thanh cong")
        elseif choice == "2" then
            io.write("Nhap ten nguoi dung can xoa: ")
            local name = io.read()
            local found = false
            for i, user in ipairs(users) do
                if user == name then
                    table.remove(users, i)
                    print("Da xoa nguoi dung: ", name)
                    found = true
                    break
                end
            end
            if not found then
                print("Khong tim thay nguoi nao nhu vay")
            end
        elseif choice ==  "3" then
            print("\nDanh sach tat ca nguoi dung:")
            for i, user in ipairs(users) do
                print(i .. "- " .. user)
            end
        elseif choice == "4" then
            break
        else
            print("Nhap sai lua chon")
        end
    end
end

local function manage_transactions()
    while true do
        print("\nQUAN LY MUON TRA SACH")
        print("1 - Muon sach")
        print("2 - Tra sach")
        print("3 - Lich su muon sach")
        print("4 - Quay lai")
        io.write("\nLua chon:")
        local choice = io.read()
        if choice == "1" then
            io.write("Nhap ten nguoi dung: ")
            local user = io.read()
            io.write("Nhap ten sach can muon: ")
            local book_name = io.read()
            io.write("Nhap ngay muon sach: ")
            local borrow_date = io.read()
            for _, book in ipairs(books) do
                if book.name == book_name and not book.is_borrowed then
                    book.is_borrowed = true
                    table.insert(transactions, {user = user, book = book_name, borrow_date = borrow_date})
                    print("Muon thanh cong")
                    break
                end
            end
        elseif choice == "2" then
            io.write("Nhap ten nguoi dung: ")
            local user = io.read()
            io.write("Nhap ten sach can tra: ")
            local book_name = io.read()
            for i, transaction in ipairs(transactions) do
                if transaction.user == user and transaction.book == book_name then
                    table.remove(transactions, i)
                    for _, book in ipairs(books) do
                        if book.name == book_name then
                            book.is_borrowed = false
                            print("Tra sach thanh cong")
                            break
                        end
                    end
                    break
                end
            end
        elseif choice == "3" then
            print("\nTat ca sach dang duoc muon")
            for _, transaction in ipairs(transactions) do
                print("Ten sach: " .. transaction.book .. ", Nguoi muon: " .. transaction.user .. ", Ngay muon: " .. transaction.borrow_date)
            end
        elseif choice == "4" then
            break
        else
            print("Nhap sai lua chon")
        end
    end
end

local function main()
    local choice
    repeat
        main_menu_display()
        choice = io.read()
        if choice == "1" then
            manage_books()
        elseif choice == "2" then
            manage_users()
        elseif choice == "3" then
            manage_transactions()
        end
    until choice == "4"
end

main()





















         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
            