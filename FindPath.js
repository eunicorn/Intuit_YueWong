var items = 
{"itemList": {"items": [
    {"id": "item1"},
    {"id": "item2","label": "Item 2"},
    {"id": "item3"},
    {"id": "item4"},
    {"id": "item5"},
    {"id": "subItem1",
        "subItems": [
            {"id": "subItem1Item1","label": "SubItem 1"},
            {"id": "subItem1Item2","label": "SubItem 2"},
            {"id": "subItem1Item3","label": "SubItem 3"}
        ]
    },
    {"id": "item6"},
    {"id": "item7","label": "Item 7"},
    {"id": "subItem2",
        "subItems": {"id": "item1","label": "SubItem 2 item1"}
    }
]}}

function isNumeric(num){
    return !isNaN(num);
}

function findPath(data, value, path)
{
    path = path || "";
    var fullpath = [];
    
    if(typeof(data) != "object" || Object.keys(data).length == 0) 
        return ( "input is not the correct type or object is empty" );

    for(var obj in data)  { 
        if (data[obj] == value)
            return ( path + "/" + obj);
            
        else if (typeof data[obj] == "object") {
            var tmpPath;
            if ( isNumeric(obj) )
                tmpPath = findPath(data[obj], value,  path + "/[" + obj + "]");
            else 
                tmpPath = findPath(data[obj], value,  path + "/" + obj);
            //console.log(tmpPath);
            if (tmpPath.length) {
                fullpath.push(tmpPath);
            }
        }
    }


    fullpath = fullpath.toString();
    return fullpath;

}

var text = findPath(items, "item2");
console.log(text)
