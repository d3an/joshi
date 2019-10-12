#ifndef PARAMETERS_H_
#define PARAMETERS_H_

class ParametersInner {
  public:
    ParametersInner() {}
    virtual ParametersInner* clone() const = 0;
    virtual double Integral(double time1, double time2) const = 0;
    virtual double IntegralSquare(double time1, double time2) const = 0;
    virtual ~ParametersInner() {}
};

class Parameters {
    ParametersInner* InnerObjectPtr;

  public:
    Parameters(const ParametersInner& innerObject);
    Parameters(const Parameters& original);
    Parameters& operator=(const Parameters& original);
    virtual ~Parameters();

    inline double Integral(double time1, double time2) const;
    inline double IntegralSquare(double time1, double time2) const;

    double Mean(double time1, double time2) const;
    double RootMeanSquare(double time1, double time2) const;
};

class ParametersConstant : public ParametersInner {
    double Constant;
    double ConstantSquare;

  public:
    ParametersConstant(double constant);
    
    virtual ParametersInner* clone() const;
    virtual double Integral(double time1, double time2) const;
    virtual double IntegralSquare(double time1, double time2) const;
};

#endif
