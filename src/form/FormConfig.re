
module BeginInputFormality = [%form

    type input = {
        total: float,
        tax: float,
        tipPercent:float,
        tip: float,
        totalPeople: int
    }

    type output = input

    let validators = {
        total: {
            strategy: OnFirstSuccessOrFirstBlur,
            validate: input =>
                switch (input.total <= 0.0) {
                    | true => Error("Total cannot be less than 0")
                    | _ => Ok(input.total)
                }
        },
        tax: {
            strategy: OnFirstSuccessOrFirstBlur,
            validate: input =>
                switch (input.tax < 0.0) {
                    | true => Error("Tax cannot be less than 0")
                    | _ => Ok(input.tax)
                }
        },
        tip: {
            strategy: OnFirstSuccessOrFirstBlur,
            validate: input =>
                switch (input.tip < 0.0) {
                    | true => Error("Tip cannot be less than 0")
                    | _ => Ok(input.tip)
                }
        },
        tipPercent: {
            strategy: OnFirstSuccessOrFirstBlur,
            validate: input =>
                switch (input.tipPercent <= 0.0) {
                    | true => Error("tipPercent cannot be less than 0")
                    | _ => Ok(input.tipPercent)
                }
        },
        totalPeople: {
            strategy: OnFirstSuccessOrFirstBlur,
            validate: input =>
                switch (input.totalPeople <= 0) {
                    | true => Error("Total People cannot be less than 0")
                    | _ => Ok(input.totalPeople)
                }
        }
    }
]
